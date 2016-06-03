/*
** rcfile.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu Jun  2 16:50:13 2016 Valentin Pichard
** Last update Fri Jun  3 18:13:28 2016 Valentin Pichard
*/

#include "sh.h"

static int	rcfile_exist(t_hs path)
{
  if (file_exist(path) == 0)
    return (0);
  else
    {
      if (create_file(path) == 0)
	return (1);
      else
	return (-1);
    }
}

int		rcfile_init(void)
{
  t_hs		path;
  t_glist_hs	to_exec;

  path = hs("~/.360sh-noscop3rc");
  if (!rcfile_exist(path))
    return (-1);
  if (!read_file(path, &to_exec))
    return (-1);
  return (0);
}
