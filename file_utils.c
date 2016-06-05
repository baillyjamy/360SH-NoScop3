/*
** file_utils.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sun Jun  5 21:00:31 2016 Valentin Pichard
** Last update Sun Jun  5 22:13:20 2016 Valentin Pichard
*/

#include "sh.h"

int		get_file_content(t_hs path, t_glist_hs *history)
{
  if (file_creator(path) < 0)
    return (-1);
  if (fshell_init(path, history) == -1)
    return (-1);
  return (0);
}

int		insert_line_file(t_hs path, t_hs line)
{
  if (file_creator(path) < 0)
    return (-1);
  if (insert_line(path, line) == -1)
    return (-1);
  return (0);
}

int		insert_lines_file(t_hs path, t_glist_hs lines)
{
  if (file_creator(path) < 0)
    return (-1);
  if (insert_lines(path, lines) == -1)
    return (-1);
  return (0);
}

int		line_exist_file(t_hs path, t_hs line)
{
  if (!file_exist(path))
    return (-1);
  return (line_exist(path, line));
}

int		lines_exist_file(t_hs path, t_glist_hs lines)
{
  if (!file_exist(path))
    return (-1);
  return (lines_exist(path, lines));
}
