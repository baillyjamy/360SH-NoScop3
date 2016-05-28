/*
** cd_errors.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu May 26 17:19:58 2016 Pierre-Emmanuel Jacquier
** Last update Thu May 26 17:19:58 2016 Pierre-Emmanuel Jacquier
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "../sh.h"

int	chdir_error(t_hs path)
{
  if (chdir(hs_to_str(path)) != 0)
    {
      egc_fprintf(STDERR_FILENO, "%hs: %s\n", path, strerror(errno));
      return (1);
    }
  return (0);
}

int	home_error(t_hs home_path)
{
  if (chdir(hs_to_str(home_path)) != 0)
    {
      fprintf(stderr, "cd: Can't change to home directory.\n");
      return (1);
    }
  return (0);
}
