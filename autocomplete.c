/*
** autocomplete.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sat Jun  4 15:25:07 2016 Valentin Pichard
** Last update Sat Jun  4 17:06:27 2016 Valentin Pichard
*/

#include <dirent.h>
#include "sh.h"

int		opendir_to_list(t_hs path, t_glist_hs *files)
{
  struct dirent *pdirent;
  DIR		*pdir;
  t_hs		line;

  if ((pdir = opendir(hs_to_str(path))) == NULL)
    return (-1);
  while ((pdirent = readdir(pdir)) != NULL)
    {
      line = hs(pdirent->d_name);
      glist_hs_append(files, line);
    }
  return (0);
}

int		sort_by_keyword(t_hs keyword, t_glist_hs *files)
{
  int		i;
  t_glist_hs	sorted;

  i = 0;
  sorted = glist_hs_new();
  while (i < glist_hs_length(files))
    {
      if (hs_starts_with(keyword, glist_hs_get(files, i)))
	glist_hs_append(&sorted, glist_hs_get(files, i));
      i++;
    }
  if (glist_hs_length(&sorted) == 0)
    return (-1);
  *files = sorted;
  return (0);
}
