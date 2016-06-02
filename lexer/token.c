/*
** token.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 12:46:19 2016 antoine
** Last update Thu Apr 28 12:46:19 2016 antoine
*/

#include <assert.h>
#include "lexer.h"
#include "../sh.h"

t_token         *token_new(t_token_type type,
                           t_position position,
                           t_hs source)
{
  t_token       *token;

  token = EGC_NEW(t_token);
  token->type = type;
  token->position = position;
  token->source = source;
  return (token);
}

t_token         *token_new_range(t_token_type type,
                                 const char *begin,
                                 const char *end)
{
  t_position    pos;
  t_hs          source;
  int           length;

  length = end - begin;
  assert(length > 0);
  source = hs_new_from_n_chars(length, begin);
  pos = lexer_get_position(begin);
  return (token_new(type, pos, source));
}

t_hs            token_to_hs(const t_token *token)
{
  return (hs_format("<%s %hs>",
                    token_type_to_str(token->type),
                    token->source));
}
