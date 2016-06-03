/*
** rcfile.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu Jun  2 16:50:13 2016 Valentin Pichard
** Last update Fri Jun  3 19:02:46 2016 Valentin Pichard
*/

#include "sh.h"

int		get_rcfile(void)
{
  t_hs		path;
  t_glist_hs	to_exec;

  path = hs("~/.360sh-noscop3rc");
  if (fshell_init(path, &to_exec) == 0)
    return (-1);
  return (0);
}
