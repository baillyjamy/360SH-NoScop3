/*
** scope_get.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 03:37:04 2016 antoine
** Last update Sun Jun  5 03:37:04 2016 antoine
*/

#include "private.h"

t_variable      *scope_get_variable(t_scope *scope, t_hs name)
{
  int           i;
  t_variable    *var;

  i = -1;
  while (++i < (int)glist_voidp_length(&scope->variables))
    {
      var = glist_voidp_get(&scope->variables, i);
      if (hs_equals(var->name, name))
        return (var);
    }
  return (NULL);
}

t_hs            scope_get(t_scope *scope, t_hs name)
{
  t_variable    *var;

  var = scope_get_variable(scope, name);
  if (!var)
    return (hs(""));
  return (var->value);
}

t_hs    scope_get_default(t_scope *scope, t_hs name, t_hs default_val)
{
  if (!scope_contains(scope, name))
    return (default_val);
  return (scope_get(scope, name));
}
