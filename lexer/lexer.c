/*
** lexer.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 07:50:24 2016 antoine
** Last update Wed Jun  1 15:14:26 2016 Valentin Pichard
*/

#include <assert.h>
#include "../sh.h"
#include "private.h"

static t_result         lex_token_impl(const char **string_p)
{
  const char            *begin;
  t_lex_function        functions[32];
  t_result              res;
  int                   i;

  i = 0;
  functions[i++] = &lex_symbols;
  functions[i++] = NULL;
  i = 0;
  while (functions[i])
    {
      begin = *string_p;
      res = (functions[i])(string_p);
      if (res.error || res.token)
        return (res);
      assert(*string_p == begin);
      i++;
    }
  return (RESULT_NULL);
}

static t_result lex_word(const char **string_p)
{
  t_result      result;
  const char    *begin;
  const char    *end;
  t_token       *token;

  begin = *string_p;
  end = begin;
  while (*end && !char_is_whitespace(*end))
    {
      result = lex_token_impl(string_p);
      if (result.error)
        return (result);
      if (result.token)
        {
          *string_p = end;
          break ;
        }
      (*string_p)++;
      end = *string_p;
    }
  if (begin == end)
    return (RESULT_NULL);
  token = TOKEN_NEW_RANGE(WORD, begin, end);
  return (RESULT_TOKEN(token));
}

static t_result         lex_token(const char **string_p)
{
  t_result              result;

  result = lex_token_impl(string_p);
  if (result.token || result.error)
    return (result);
  result = lex_word(string_p);
  if (result.token || result.error)
    return (result);
  return (RESULT_ERROR(hs("Unexpected character"), *string_p));
}

static t_lexer_result   lex_from_str(const char *string)
{
  t_token_list          *tokens;
  t_result              res;

  tokens = NULL;
  while (*string)
    {
      skip_whitespaces(&string);
      if (!*string)
        break ;
      res = lex_token(&string);
      if (res.error)
        return ((t_lexer_result){.tokens = NULL, .error = res.error});
      token_list_add(&tokens, res.token);
    }
  return ((t_lexer_result){.tokens = tokens, .error = NULL});
}

t_lexer_result          lex(t_hs string)
{
  t_lexer_result        r;
  const char            *cstr;

  cstr = hs_to_str(string);
  STATICS->lexer_input_string = cstr;
  r = lex_from_str(cstr);
  STATICS->lexer_input_string = NULL;
  return (r);
}
