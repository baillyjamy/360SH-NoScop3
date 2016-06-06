/*
** parser.c for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Fri Jun 03 11:18:33 2016 Antoine Baudrand
** Last update Sat Jun 04 19:42:17 2016 Antoine Baudrand
*/

#include <assert.h>
#include "private.h"

t_token_result          parse_token_type(t_token_list **list_pointer,
                                         t_token_type type,
                                         t_redir *redir)
{
  t_token_result        result;
  t_token_list          *begin;
  t_redir               begin_redir;

  begin_redir = *redir;
  begin = *list_pointer;
  result = parse_token(list_pointer, redir);
  if (!result.token)
    return (result);
  if (result.token->type != type)
    {
      *redir = begin_redir;
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
  t_redir               begin_redir;

  begin_redir = *redir;
  begin = *list_ptr;
  result = parse_token(list_ptr, redir);
  if (hs_length(result.error) || !result.token)
    return (result);
  if (!parser_is_word_or_string(result.token))
    {
      *redir = begin_redir;
      *list_ptr = begin;
      return (TOKEN_RESULT_NULL);
    }
  return (result);
}

int                     parse_word_or_string(t_token_list **list_pointer,
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
