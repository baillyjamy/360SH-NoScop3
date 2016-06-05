/*
** read.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/files/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:15:40 2016 Valentin Pichard
** Last update Fri Jun  3 19:04:30 2016 Valentin Pichard
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "sh_file.h"

ssize_t		get_file_length(const t_hs filename)
{
  struct stat	fstat;

  if (stat(hs_to_str(filename), &fstat) != -1)
    return (fstat.st_size);
  return (-1);
}

int		read_file(const t_hs filename, t_glist_hs *lines)
{
  char		*data;
  int		fd;
  ssize_t	file_length;
  t_hs		ths;
  t_glist_hs	new_lines;

  if ((file_length = get_file_length(filename)) == -1 &&
     (data = egc_malloc_atomic(file_length + 1)) == NULL)
    return (-1);
  if ((fd = open_file(filename, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, data, get_file_length(filename)) == -1)
    {
      close(fd);
      return (-1);
    }
  close(fd);
  /*ths = hs(data);
  if ((int)hs_length(ths) != file_length)
    return (-1);
  new_lines = hs_split(ths, hs("\n"));
  glist_hs_append_all(lines, &new_lines);*/
  return (0);
}
