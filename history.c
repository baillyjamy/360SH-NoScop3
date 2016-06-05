/*
** history.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu Jun  2 16:49:54 2016 Valentin Pichard
** Last update Sun Jun  5 19:01:14 2016 Valentin Pichard
*/

#include "sh.h"

int		get_history(t_glist_hs *history)
{
  t_hs		path;

  path = hs("~/.360sh-noscop3_history");
  if (fshell_init(path, history) == -1)
    return (-1);
  return (0);
}

int		add_line_history(t_hs line)
{
  t_hs		path;

  path = hs("~/.360sh-noscop3_history");
  if (insert_line(path, line) == -1)
    return (-1);
  return (0);
}
