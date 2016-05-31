/*
** unsetenv.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri May 27 17:16:54 2016 Pierre-Emmanuel Jacquier
** Last update Fri May 27 17:16:54 2016 Pierre-Emmanuel Jacquier
*/

#include "../sh.h"

void	unsetenv_cmd(t_glist_hs *argv)
{
  int	i;

  i = 1;
  if (glist_hs_length(argv) == 2)
    {
      if (hs_equals(glist_hs_get(argv, 1), hs("*")))
	env_remove_all_variable();
    }
  while (i < glist_hs_length(argv))
    env_remove_variable(glist_hs_get(argv, i++));
}
