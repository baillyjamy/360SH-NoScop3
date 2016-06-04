/*
** lex_heredoc.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Jun  4 16:10:26 2016 antoine
** Last update Sat Jun  4 16:10:26 2016 antoine
*/

#include "private.h"

static t_result create_heredoc(t_hs value, const char *begin, const char *end)
{
  t_token       *token;

  token = TOKEN_NEW_RANGE(HEREDOC, begin, end);
  token->string_value = value;
  return (RESULT_TOKEN(token));
}

static t_hs     read_until_whitespace(const char **string_p)
{
  t_hs          word;

  word = hs("");
  while (**string_p && !char_is_whitespace(**string_p))
    {
      word = hs_concat_hs_char(word, **string_p);
      NEXT(string_p);
    }
  return (word);
}

static t_result lex_end(const char *begin, const char **string_p, t_hs delim)
{
  t_hs          value;
  char          c;
  const char    *end_delim_str;
  const char    *end;

  value = hs("");
  end_delim_str = hs_to_str(hs_format("\n%hs\n", delim));
  while ((c = **string_p))
    {
      end = *string_p;
      if (lexer_read_string(end_delim_str, string_p))
        return (create_heredoc(value, begin, end));
      value = hs_concat_hs_char(value, c);
      NEXT(string_p);
    }
  return (RESULT_ERROR(hs("Expected here document end delimiter"), begin));
}

t_result        lex_heredoc(const char **string_p)
{
  const char    *begin;
  t_hs          end;

  begin = *string_p;
  if (lexer_read_string("<<", string_p))
    {
      end = read_until_whitespace(string_p);
      if (!hs_length(end))
        return (RESULT_ERROR(hs("Missing name for redirect."), *string_p));
      return (lex_end(begin, string_p, end));
    }
  *string_p = begin;
  return (RESULT_NULL);
}
