/*
** file.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/files/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:18:20 2016 Valentin Pichard
** Last update Mon May 30 18:43:59 2016 Valentin Pichard
*/

#include "file.h"

int		open_file(const t_hs pathname, int mode)
{
  int		fd;

  fd = open(hs_to_str(pathname), mode, 00644);
  return (fd);
}

void		close_file(int fd)
{
  close(fd);
}

void		create_file(const t_hs filename)
{
  close_file(open_file(filename, O_CREAT));
}

void		reset_file(const t_hs filename)
{
  close_file(open_file(filename, O_RDWR | O_TRUNC));
}

int		edit_file(const t_hs filename)
{
  int		fd;

  fd = open_file(filename, O_APPEND);
  return (fd);
}
