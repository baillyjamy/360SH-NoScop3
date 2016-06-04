/*
** is_dir.c for file in /home/antoine/360SH-NoScop3/file
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Sat Jun 04 19:51:30 2016 Antoine Baudrand
** Last update Sat Jun 04 19:51:49 2016 Antoine Baudrand
*/

#include <sys/stat.h>
#include "sh_file.h"

int	        is_dir(char *file_name)
{
  struct stat	file_stat;

  if (stat(file_name, &file_stat) != 0)
    return (0);
  else if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
    return (1);
  return (0);
}
