/*
** autocomplete.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sat Jun  4 15:25:07 2016 Valentin Pichard
** Last update Sat Jun  4 16:58:31 2016 Valentin Pichard
*/

#include <dirent.h>
#include "sh.h"

int		opendir_to_list(t_hs path, t_glist_hs *files)
{
  struct dirent *pdirent;
  DIR		*pdir;
  int		i;
  t_hs		line;

  i = 0;
  if ((pdir = opendir(hs_to_str(path))) == NULL)
    return (-1);
  while ((pdirent = readdir(pdir)) != NULL)
    {
      line = hs(pdirent->d_name);
      glist_hs_set(files, i, line);
      i++;
    }
  return (0);
}
