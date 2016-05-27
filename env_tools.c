/*
** env_tools.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Fri May 27 00:38:48 2016 Valentin Pichard
** Last update Fri May 27 00:39:15 2016 Valentin Pichard
*/

#include "sh.h"

int		env_variable_exists(t_hs name)
{
  t_hs		dummy;

  return (env_get_variable(name, &dummy) == 0);
}

void		env_create_variable(t_hs name, t_hs value)
{
  t_hs          line;

  line = hs_format("%hs=%hs", name, value);
  glist_hs_append(&STATICS->env, line);
}
