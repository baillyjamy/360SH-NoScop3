/*
** parser_1.c for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Sat Jun 04 19:34:39 2016 Antoine Baudrand
** Last update Sat Jun 04 19:56:55 2016 Antoine Baudrand
*/

#include <assert.h>
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
  error = parse_redir(list_pointer, redir);
  if (hs_length(error))
    return ((t_token_result){.error = error, .token = NULL});
  return ((t_token_result){.error = hs(""), .token = token});
}
