/*
** history.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/bltins/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon Jun  6 19:09:11 2016 Valentin Pichard
** Last update Mon Jun  6 20:26:31 2016 Valentin Pichard
*/

#include "../sh.h"

int		history_cmd(t_glist_hs *argv)
{
  int		i;
  t_glist_hs	history;
  t_hs		path;

  (void)argv;
  history = glist_hs_new();
  path = path_history();
  i = 0;
  if (get_file_content(path, &history) == -1)
    return (-1);
  while (i < glist_hs_length(&history) - 1)
    {
      if (i >= 10000)
	return (0);
      egc_fprintf(STATICS->out,
		  " %d\t%hs\n",
		  (i + 1), glist_hs_get(&history, i));
      i++;
    }
  return (0);
}
