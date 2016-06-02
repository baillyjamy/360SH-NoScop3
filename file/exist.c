/*
** exist.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/files/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:14:18 2016 Valentin Pichard
** Last update Thu Jun  2 23:01:16 2016 Valentin Pichard
*/

#include "file.h"

int		line_exist(const t_hs filename, const t_hs line)
{
  t_glist_hs	lines;
  int		i;
  t_hs		sline;

  i = 0;
  lines = glist_hs_new();
  if (read_file(filename, &lines) == -1)
    return (-1);
  while (i < glist_hs_length(&lines))
    {
      sline = glist_hs_get(&lines, i++);
      if (hs_equals(sline, line))
	return (1);
    }
  return (0);
}

int		lines_exist(const t_hs filename, const t_glist_hs lines)
{
  t_hs		line;
  int		i;

  i = 0;
  while (i < glist_hs_length(&lines))
    {
      line = glist_hs_get(&lines, i++);
      if (line_exist(filename, line) == 0)
	return (0);
      else if (line_exist(filename, line) == -1)
	return (-1);
    }
  return (1);
}
