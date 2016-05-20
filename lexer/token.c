/*
** token.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 12:46:19 2016 antoine
** Last update Thu Apr 28 12:46:19 2016 antoine
*/

#include "lexer.h"

static void     skip_word(const char **string_pointer)
{
  while (**string_pointer)
    (*string_pointer)++;
}

static const char       *token_type_to_str(t_token_type type)
{
  const char            *string;

  string = ("string\0"
            "word\0"
            "semicolon\0"
            "\0");
  while (*string)
    {
      if (!type)
        return (string);
      type--;
      skip_word(&string);
      string++;
    }
  abort();
}

t_hs                    token_to_hs(const t_token *token)
{
  return (hs_format("<%s %hs>",
                    token_type_to_str(token->type),
                    token->string));
}

t_hs                    token_list_to_hs(const t_token_list *tokens)
{
  t_hs                  s;

  s = hs_new_empty();
  while (tokens)
    {
      s = hs_concat(s, token_to_hs(tokens->token));
      tokens = tokens->next;
    }
  return (s);
}
