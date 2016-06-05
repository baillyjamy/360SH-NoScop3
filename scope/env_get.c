/*
** env_get.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 21:05:46 2016 antoine
** Last update Sun Jun  5 21:05:46 2016 antoine
*/

#include "scope.h"
#include "../sh.h"

t_hs    env_get(t_hs name)
{
  return (scope_get(&STATICS->env, name));
}

t_hs    env_get_default(t_hs name, t_hs default_val)
{
  return (scope_get_default(&STATICS->env, name, default_val));
}
