/*
** parser.c for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Fri Jun 03 11:18:33 2016 Antoine Baudrand
** Last update Fri Jun 03 21:22:20 2016 Antoine Baudrand
*/

#include "private.h"

t_hs    parser_get_word(t_token *token)
{
  if (token->type == TOKEN_TYPE_WORD)
    return (token->source);
  else
    return (token->string_value);
}

int             parser_is_word_or_string(t_token *token)
{
  t_token_type  t;

  t = token->type;
  return (t == TOKEN_TYPE_D_QUOTES ||
          t == TOKEN_TYPE_S_QUOTES ||
          t == TOKEN_TYPE_WORD);
}

/*
** Try to read a token.
**
** Return a token or NULL.
*/
t_token         *parse_token_impl(t_token_list **list_pointer)
{
  t_token       *token;

  if (!*list_pointer)
    return (NULL);
  token = (*list_pointer)->token;
  *list_pointer = (*list_pointer)->next;
  return (token);
}

/*
** Try to read a token.
**
** Return a token or NULL.
*/
t_token         *parse_token_type_impl(t_token_list **list_pointer,
                                       t_token_type type)
{
  t_token       *token;

  if (!*list_pointer)
    return (NULL);
  token = (*list_pointer)->token;
  if (type != token->type)
    return (NULL);
  *list_pointer = (*list_pointer)->next;
  return (token);
}

t_token_result  parse_token(t_token_list **list_pointer, t_redir *redir)
{
  t_token       *token;
  t_hs          error;

  error = parse_redir(list_pointer, redir);
  if (hs_length(error))
    return ((t_token_result){.error = error, .token = NULL});
  token = parse_token_impl(list_pointer);
  if (!token)
    return (TOKEN_RESULT_NULL);
  return ((t_token_result){.error = hs(""), .token = token});
}

t_token_result          parse_token_type(t_token_list **list_pointer,
                                         t_token_type type,
                                         t_redir *redir)
{
  t_token_result        result;
  t_token_list          *begin;

  begin = *list_pointer;
  result = parse_token(list_pointer, redir);
  if (!result.token)
    return (result);
  if (result.token->type != type)
    {
      *list_pointer = begin;
      return (TOKEN_RESULT_NULL);
    }
  return (result);
}

/*
** Returns a token, an error or TOKEN_RESULT_NULL.
*/
t_token_result          parse_word_or_string_token(t_token_list **list_ptr,
                                                   t_redir *redir)
{
  t_token_result        result;
  t_token_list          *begin;

  begin = *list_ptr;
  result = parse_token(list_ptr, redir);
  if (hs_length(result.error) || !result.token)
    return (result);
  if (!parser_is_word_or_string(result.token))
    {
      *list_ptr = begin;
      return (TOKEN_RESULT_NULL);
    }
  return (result);
}

int             parse_word_or_string(t_token_list **list_pointer,
                                     t_hs *result,
                                     t_redir *redir)
{
  t_token_result        tr;

  tr = parse_word_or_string_token(list_pointer, redir);
  if (TOKEN_RESULT_IS_NULL(tr))
    {
      *result = hs("");
      return (0);
    }
  if (hs_length(tr.error))
    {
      *result = tr.error;
      return (-1);
    }
  *result = parser_get_word(tr.token);
  return (0);
}

t_parser_result parse_command_end(t_token_list **list_pointer,
                                  t_node *node)
{
  t_hs          word;

  while (1)
    {
      if (parse_word_or_string(list_pointer, &word, &node->redir))
        return (ERROR(word));
      if (!hs_length(word))
        break ;
      glist_hs_append(&node->args, word);
    }
  return (NODE(node));
}

t_parser_result parse_command(t_token_list **list_pointer)
{
  t_node        *node;
  t_hs          word;
  t_redir       redir;

  parser_redir_init(&redir);
  if (parse_word_or_string(list_pointer, &word, &redir))
    return (ERROR(word));
  if (!hs_length(word))
    return (NULL_RESULT);
  node = node_new(NODE_COMMAND, &redir);
  node->args = glist_hs_new();
  glist_hs_append(&node->args, word);
  return (parse_command_end(list_pointer, node));
}

t_node          *node_new_empty_list(void)
{
  t_node        *node;
  t_redir       redir;

  parser_redir_init(&redir);
  node = node_new(NODE_LIST, &redir);
  node->children = glist_voidp_new();
  return (node);
}

t_parser_result         parse(t_token_list *tokens)
{
  t_parser_result       result;
  t_node                *node;

  result = parse_command(&tokens);
  if (!result.success)
    return (result);
  if (tokens)
    {
      return (ERROR(hs_format("Unexpected token '%hs'",
                              tokens->token->source)));
    }
  if (!result.node)
    {
      node = node_new_empty_list();
      return (NODE(node));
    }
  return (result);
}
