/*
** variable.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 00:39:41 2016 antoine
** Last update Sun Jun  5 00:39:41 2016 antoine
*/

#include "private.h"

t_variable      *variable_new(t_hs name, t_hs value)
{
  t_variable    *var;

  var = EGC_NEW(t_variable);
  var->name = name;
  var->value = value;
  return (var);
}

t_variable      *variable_from_hs(t_hs string)
{
  int           i;
  t_hs          name;
  t_hs          value;

  i = hs_find_char(string, '=', 0);
  if (i == -1 || i == 0)
    return (NULL);
  name = hs_slice(string, 0, i);
  value = hs_slice(string, i + 1, hs_length(string));
  return (variable_new(name, value));
}

t_hs    variable_to_hs(const t_variable *variable)
{
  return (hs_format("%hs=%hs", variable->name, variable->value));
}
