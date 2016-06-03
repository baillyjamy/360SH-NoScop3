/*
** exist.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/files/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:14:18 2016 Valentin Pichard
** Last update Fri Jun  3 19:01:59 2016 Valentin Pichard
*/

#include <sys/stat.h>
#include "file.h"

int		file_exist(const t_hs filename)
{
  struct stat   fstat;

  if (stat(hs_to_str(filename), &fstat) == 0)
    return (1);
  return (0);
}

int		fshell_init(t_hs path, t_glist_hs *lines)
{
  if (!file_exist(path))
    return (-1);
  if (read_file(path, lines) == -1)
    return (-1);
  return (0);
}

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
