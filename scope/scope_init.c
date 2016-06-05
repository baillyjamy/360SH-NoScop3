/*
** scope_init.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 03:37:43 2016 antoine
** Last update Sun Jun  5 03:37:43 2016 antoine
*/

#include "private.h"

void    scope_init(t_scope *scope)
{
  scope->variables = glist_voidp_new();
}

void    scope_remove_all(t_scope *scope)
{
  scope->variables = glist_voidp_new();
}

void            scope_init_from_str_array(t_scope *scope, char **array)
{
  t_variable    *var;

  scope_init(scope);
  while (*array)
    {
      var = variable_from_hs(hs(*array));
      if (var)
        scope_add_variable(scope, var);
      array++;
    }
}
