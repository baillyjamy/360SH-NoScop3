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
  t_hs		lel;

  return (get_env_line(name, &lel) == 0);
}

void		env_variable_creator(t_hs name, t_hs value)
{
  glist_hs_append(&STATICS->env,
		  hs_concat(hs_concat_hs_char(name, '='),
			    value));
}
