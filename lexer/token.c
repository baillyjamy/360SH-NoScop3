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

  token = egc_malloc(sizeof(t_token));
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

static void     skip_word(const char **string_pointer)
{
  while (**string_pointer)
    (*string_pointer)++;
}

static const char       *token_type_to_str(t_token_type type)
{
  const char            *string;

  string = ("and\0and_and\0heredoc\0left_paren\0pipe\0pipe_pipe\0"
            "right_paren\0semicolon\0string\0word\0\0");
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

t_hs            token_to_hs(const t_token *token)
{
  return (hs_format("<%s %hs>",
                    token_type_to_str(token->type),
                    token->source));
}

t_token_list    *token_list_new(t_token *token, t_token_list *next)
{
  t_token_list  *list;

  list = egc_malloc(sizeof(t_token_list));
  list->token = token;
  list->next = next;
  return (list);
}

t_token_list    *token_list_last(t_token_list *token_list)
{
  if (!token_list)
    return (NULL);
  if (!token_list->next)
    return (token_list);
  return (token_list_last(token_list->next));
}

void            token_list_add(t_token_list **list_pointer, t_token *token)
{
  t_token_list  *last;
  t_token_list  *new;

  new = token_list_new(token, NULL);
  last = token_list_last(*list_pointer);
  if (!last)
    {
      *list_pointer = new;
      return ;
    }
  last->next = new;
}

t_hs    token_list_to_hs(const t_token_list *tokens)
{
  t_hs  s;

  s = hs_new_empty();
  while (tokens)
    {
      s = hs_concat(s, token_to_hs(tokens->token));
      tokens = tokens->next;
    }
  return (s);
}
