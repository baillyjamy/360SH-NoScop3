/*
** lexer.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 07:50:24 2016 antoine
** Last update Thu Apr 28 07:50:24 2016 antoine
*/

#include "assert.h"
#include "lexer_private.h"

static t_result         lex_word(const char **string_p)
{
  return (RESULT_NULL);
}

static void             skip_whitespaces(const char **string_p)
{
  while (char_is_whitespace(**string_p))
    NEXT(string_p);
}

static t_result         lex_token(const char **string_p)
{
  const char            *begin;
  t_lex_function        functions[32];
  t_result              res;
  int                   i;

  i = 0;
  functions[i++] = lex_word;
  functions[i++] = NULL;
  i = 0;
  while (functions[i])
    {
      begin = *string_p;
      res = functions[i](string_p);
      if (res.error || res.token)
        return (res);
      assert(*string_p == begin);
      i++;
    }
  return (RESULT_NULL);
}

static t_lexer_result   lex_from_str(const char *string)
{
  t_token_list          *tokens;
  t_result              res;

  tokens = NULL;
  while (*string)
    {
      skip_whitespaces(&string);
      res = lex_token(&string);
      if (res.error)
        return ((t_lexer_result){.tokens = NULL, .error = res.error});
      token_list_add(&tokens, res.token);
    }
  return ((t_lexer_result){.tokens = tokens, .error = NULL});
}

t_lexer_result  lex(t_hs string)
{
  return (lex_from_str(hs_to_str(string)));
}
