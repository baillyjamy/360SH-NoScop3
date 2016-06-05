/*
** scope_to_hs.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 03:38:14 2016 antoine
** Last update Sun Jun  5 03:38:14 2016 antoine
*/

#include "private.h"

t_glist_hs      scope_to_glist(t_scope *scope)
{
  t_glist_hs    list;
  int           i;
  t_variable    *var;

  list = glist_hs_new();
  i = -1;
  while (++i < glist_voidp_length(&scope->variables))
    {
      var = glist_voidp_get(&scope->variables, i);
      glist_hs_append(&list, variable_to_hs(var));
    }
  return (list);
}

t_hs            scope_to_hs(t_scope *scope)
{
  t_glist_hs    list;

  list = scope_to_glist(scope);
  return (hs_join(hs("\n"), &list));
}
