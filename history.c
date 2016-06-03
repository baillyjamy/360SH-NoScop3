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

int		get_history(void)
{
  t_hs		path;
  t_glist_hs	history;

  path = hs("~/.360sh-noscop3_history");
  if (fshell_init(path, &history) == -1)
    return (-1);
  return (0);
}
