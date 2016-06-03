/*
** history.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu Jun  2 16:49:54 2016 Valentin Pichard
** Last update Fri Jun  3 19:02:07 2016 Valentin Pichard
*/

#include "sh.h"

int		get_history(t_glist_hs *history)
{
  t_hs		path;

  path = hs("~/.360sh-noscop3_history");
  if (fshell_init(path, history))
    return (-1);
  return (0);
}
