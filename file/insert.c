/*
** insert.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/files/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:12:36 2016 Valentin Pichard
** Last update Thu Jun  2 11:42:51 2016 Valentin Pichard
*/

#include "sh_file.h"

int		insert_line(const t_hs filename, const t_hs line)
{
  int		fd;

  if ((fd = edit_file(filename)) == -1)
    return (-1);
  write(fd, hs_to_str(hs_concat_hs_char(line, '\n')), hs_length(line) + 1);
  close(fd);
  return (0);
}

int		insert_lines(const t_hs filename, const t_glist_hs lines)
{
  int		i;
  t_hs		line;

  i = 0;
  while (i < glist_hs_length(&lines))
    {
      line = glist_hs_get(&lines, i);
      if (insert_line(filename, line) == -1)
	return (-1);
      i++;
    }
  return (0);
}
