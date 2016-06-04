/*
** lex_d_quotes.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Jun  4 16:10:51 2016 antoine
** Last update Sat Jun  4 16:10:51 2016 antoine
*/

#include "private.h"

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
