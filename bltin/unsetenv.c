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
  while (i < glist_hs_length(argv))
    unset_env(glist_hs_get(argv, i++));
}
