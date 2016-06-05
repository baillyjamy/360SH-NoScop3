/*
** env.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 01:28:43 2016 antoine
** Last update Sun Jun  5 01:28:43 2016 antoine
*/

#include "scope.h"
#include "../sh.h"

void    env_set(t_hs name, t_hs value)
{
  scope_set(&STATICS->env, name, value);
}

t_hs    env_get(t_hs name)
{
  return (scope_get(&STATICS->env, name));
}

t_hs    env_get_default(t_hs name, t_hs default_val)
{
  return (scope_get_default(&STATICS->env, name, default_val));
}

t_hs    env_remove(t_hs name)
{
  return (scope_remove(&STATICS->env, name));
}

int     env_contains(t_hs name)
{
  return (scope_contains(&STATICS->env, name));
}

void    env_remove_all(void)
{
  return (scope_remove_all(&STATICS->env));
}

t_hs    env_to_hs(void)
{
  return (scope_to_hs(&STATICS->env));
}
