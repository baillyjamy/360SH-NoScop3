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
  const char    *begin;

  begin = *string_p;
  while (**string_p == *exp)
    {
      if (!*exp)
        break ;
      NEXT(string_p);
      NEXT(&exp);
    }
  if (*exp)
    {
      *string_p = begin;
      return (0);
    }
  return (1);
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
  return (RESULT_NULL);
}

static t_result create_d_quotes(t_hs value,
                                const char *begin,
                                const char *end)
{
  t_token       *token;

  token = TOKEN_NEW_RANGE(D_QUOTES, begin, end);
  token->string_value = value;
  return (RESULT_TOKEN(token));
}

static t_result lex_end(const char **string_p, const char *begin)
{
  t_hs          value;
  char          c;

  value = hs("");
  while ((c = **string_p))
    {
      if (c == '"')
        {
          NEXT(string_p);
          return (create_d_quotes(value, begin, *string_p));
        }
      value = hs_concat_hs_char(value, c);
      NEXT(string_p);
    }
  return (RESULT_ERROR(hs("Expected '\"'"), begin));
}

t_result        lex_d_quotes(const char **string_p)
{
  const char    *begin;

  begin = *string_p;
  if (*begin != '"')
    return (RESULT_NULL);
  NEXT(string_p);
  return (lex_end(string_p, begin));
}
