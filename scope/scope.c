/*
** scope.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Jun  4 23:36:19 2016 antoine
** Last update Sat Jun  4 23:36:19 2016 antoine
*/

#include "private.h"

t_hs            scope_remove(t_scope *scope, t_hs name)
{
  int           i;
  t_variable    *var;

  i = -1;
  while (++i < (int)glist_voidp_length(&scope->variables))
    {
      var = glist_voidp_get(&scope->variables, i);
      if (hs_equals(var->name, name))
        {
          glist_voidp_remove(&scope->variables, i);
          return (var->value);
        }
    }
  return (hs(""));
}

int     scope_contains(t_scope *scope, t_hs name)
{
  return (scope_get_variable(scope, name) != NULL);
}

void    scope_add_variable(t_scope *scope, t_variable *var)
{
  glist_voidp_append(&scope->variables, var);
}

void            scope_set(t_scope *scope, t_hs name, t_hs value)
{
  t_variable    *var;

  var = scope_get_variable(scope, name);
  if (!var)
    {
      scope_add_variable(scope, variable_new(name, value));
      return ;
    }
  var->value = value;
}
