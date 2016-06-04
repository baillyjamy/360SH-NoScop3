/*
** file.c for file in /home/antoine/360SH-NoScop3/file
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:18:20 2016 Valentin Pichard
** Last update Sat Jun 04 11:57:29 2016 Antoine Baudrand
*/

#include <sys/stat.h>
#include <sys/types.h>
#include "file.h"

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


int	        is_dir(char *file_name)
{
  struct stat	file_stat;

  if (stat(file_name, &file_stat) != 0)
    return (0);
  else if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
    return (1);
  return (0);
}
