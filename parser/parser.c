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

/*
** Try to read a token.
**
** Return a token or NULL.
*/
t_token         *parse_token_type(t_token_list **list_pointer,
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

t_token         *parse_word_or_string_token(t_token_list **list_pointer)
{
  t_token       *token;

  token = parse_token_type(list_pointer, TOKEN_TYPE_WORD);
  if (token)
    return (token);
  token = parse_token_type(list_pointer, TOKEN_TYPE_D_QUOTES);
  if (token)
    return (token);
  token = parse_token_type(list_pointer, TOKEN_TYPE_S_QUOTES);
  if (token)
    return (token);
  return (NULL);
}

int             parse_word_or_string(t_token_list **list_pointer,
                                     t_hs *result)
{
  t_token       *token;

  token = parse_word_or_string_token(list_pointer);
  if (!token)
    return (-1);
  if (token->type == TOKEN_TYPE_WORD)
    *result = token->source;
  else
    *result = token->string_value;
  return (0);
}

t_parser_result parse_command_end(t_token_list **list_pointer,
                                  t_node *node)
{
  t_hs          word;

  while (1)
    {
      if (parse_word_or_string(list_pointer, &word))
        break ;
      glist_hs_append(&node->args, word);
    }
  return (NODE(node));
}

t_parser_result parse_command(t_token_list **list_pointer)
{
  t_node        *node;
  t_hs          word;

  if (!*list_pointer)
    return (NULL_RESULT);
  if (parse_word_or_string(list_pointer, &word))
    return (NULL_RESULT);
  node = node_new(NODE_COMMAND);
  node->args = glist_hs_new();
  glist_hs_append(&node->args, word);
  return (parse_command_end(list_pointer, node));
}

t_node          *node_new_empty_list(void)
{
  t_node        *node;

  node = node_new(NODE_LIST);
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
