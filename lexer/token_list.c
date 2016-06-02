/*
** token_list.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Jun  2 15:47:39 2016 antoine
** Last update Thu Jun  2 15:47:39 2016 antoine
*/

#include "private.h"

t_token_list    *token_list_new(t_token *token, t_token_list *next)
{
  t_token_list  *list;

  list = EGC_NEW(t_token_list);
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
