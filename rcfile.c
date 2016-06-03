/*
** rcfile.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu Jun  2 16:50:13 2016 Valentin Pichard
** Last update Fri Jun  3 17:34:07 2016 Valentin Pichard
*/

#include "sh.h"

int		rcfile_exist(void)
{
  if (file_exist(hs("~/.360sh-noscop3rc")) == 0)
    return (0);
  else
    {
      if (create_file(hs("~/.360sh-noscop3rc")) == 0)
	return (1);
      else
	return (-1);
    }
}
