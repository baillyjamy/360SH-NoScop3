/*
** file.c for file in /home/antoine/360SH-NoScop3/file
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:18:20 2016 Valentin Pichard
** Last update Sat Jun 04 19:51:22 2016 Antoine Baudrand
*/

#include <fcntl.h>
#include <sys/stat.h>
#include "sh_file.h"

int		file_creator(t_hs path)
{
  if (file_exist(path))
    return (0);
  else
    {
      if (create_file(path) == 0)
	return (1);
      else
	return (-1);
    }
}

int		open_file(const t_hs pathname, int mode)
{
  return (open(hs_to_str(pathname), mode, 00644));
}

int		create_file(const t_hs filename)
{
  int		fd;

  if ((fd = open_file(filename, O_RDWR | O_CREAT)) == -1)
    {
      close(fd);
      egc_printf("GFDSQSDFG -- %i --- %hs", fd, filename);
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
