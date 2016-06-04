/*
** lex_symbols.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Jun  2 16:34:34 2016 antoine
** Last update Thu Jun  2 16:34:34 2016 antoine
*/

#include "private.h"

static int      read_string(const char *exp, const char **string_p)
{
  return (lexer_read_string(exp, string_p));
}

t_result        lex_symbols(const char **string_p)
{
  const char    *begin;

  begin = *string_p;
  if (read_string("<", string_p))
    return (RESULT_TOKEN_RANGE(LT, begin, *string_p));
  if (read_string(">", string_p))
    return (RESULT_TOKEN_RANGE(GT, begin, *string_p));
  if (read_string("&&", string_p))
    return (RESULT_TOKEN_RANGE(AND_AND, begin, *string_p));
  if (read_string("&", string_p))
    return (RESULT_TOKEN_RANGE(AND, begin, *string_p));
  if (read_string("||", string_p))
    return (RESULT_TOKEN_RANGE(PIPE_PIPE, begin, *string_p));
  if (read_string("|", string_p))
    return (RESULT_TOKEN_RANGE(PIPE, begin, *string_p));
  if (read_string("(", string_p))
    return (RESULT_TOKEN_RANGE(LEFT_PAREN, begin, *string_p));
  if (read_string(")", string_p))
    return (RESULT_TOKEN_RANGE(RIGHT_PAREN, begin, *string_p));
  if (read_string(";", string_p))
    return (RESULT_TOKEN_RANGE(SEMICOLON, begin, *string_p));
  return (RESULT_NULL);
}
