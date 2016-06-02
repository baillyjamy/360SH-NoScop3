/*
** file.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/files/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:18:20 2016 Valentin Pichard
** Last update Thu Jun  2 10:51:39 2016 Valentin Pichard
*/

#include "file.h"

int		open_file(const t_hs pathname, int mode)
{
  return (open(hs_to_str(pathname), mode, 00644));
}

int		create_file(const t_hs filename)
{
  int		fd;

  if ((fd = open_file(filename, O_CREAT)) == -1)
    {
      close(fd);
      return (-1);
    }
  close(fd);
  return (0);
}

int		reset_file(const t_hs filename)
{
  int		fd;

  if ((fd = open_file(filename, O_RDWR | O_TRUNC)) == -1)
    {
      close(fd);
      return (-1);
    }
  close(fd);
  return (0);
}

int		edit_file(const t_hs filename)
{
  int		fd;

  if ((fd = open_file(filename, O_RDWR | O_APPEND)) == -1)
    {
      close(fd);
      return (-1);
    }
  return (fd);
}
