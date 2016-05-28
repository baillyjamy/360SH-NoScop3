/*
** lexer.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 07:50:24 2016 antoine
** Last update Thu Apr 28 07:50:24 2016 antoine
*/

#include <assert.h>
#include "../sh.h"
#include "private.h"

static void             skip_whitespaces(const char **string_p)
{
  while (char_is_whitespace(**string_p))
    NEXT(string_p);
}

static t_result         lex_token_impl(const char **string_p)
{
  const char            *begin;
  t_lex_function        functions[32];
  t_result              res;
  int                   i;

  i = 0;
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

t_result                lex_word(const char **string_p)
{
  t_result              result;
  const char            *begin;
  const char            *end;

  begin = *string_p;
  while (**string_p)
    {
      end = *string_p;
      result = lex_token_impl(string_p);
      if (result.error)
        return (result);
      if (result.token)
        break;
    }
  if (begin == end)
    return (RESULT_NULL);
  return (RESULT_TOKEN(TOKEN_NEW_RANGE(WORD, begin, end)));
}

static t_result         lex_token(const char **string_p)
{
  t_result              result;

  result = lex_token(string_p);
  if (result.token || result.error)
    return (result);
  return (lex_word(string_p));
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

t_position              lexer_get_position(const char *char_addr)
{
  const char            *string;
  t_position            position;

  position_init(&position);
  string = STATICS->lexer_input_string;
  assert(char_addr >= string);
  while (string < char_addr)
    {
      if (*string == '\n')
        {
          position.line++;
          position.column = 0;
        }
      position.column++;
      position.index++;
      string++;
    }
  return (position);
}
