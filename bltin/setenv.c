/*
** setenv.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri May 27 12:14:26 2016 Pierre-Emmanuel Jacquier
** Last update Fri May 27 12:14:26 2016 Pierre-Emmanuel Jacquier
*/

#include <unistd.h>
#include <stdio.h>
#include "../sh.h"

static int      is_valid_variable_name(t_hs name)
{
  int           i;
  char          c;

  i = -1;
  while (++i < (int)hs_length(name))
    {
      c = hs_get(name, i);
      if (!char_is_alpha_numeric(c) && c != '_')
	return (0);
    }
  return (1);
}

static int	check_variable_name(t_hs name)
{
  if (!hs_length(name) || !char_is_alpha(hs_get(name, 0)))
    {
      fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
      return (1);
    }
  if (!is_valid_variable_name(name))
    {
      fprintf(stderr,
              "setenv: Variable name must contain alphanumeric "
              "characters.\n");
      return (1);
    }
  return (0);
}

static int	set_variable(t_hs name, t_hs value)
{
  if (!check_variable_name(name))
    env_set_variable(name, value);
  return (1);
}

int	setenv_cmd(t_glist_hs *argv)
{
  if (glist_hs_length(argv) > 3)
    return (egc_fprintf(STDERR_FILENO, "setenv: Too many arguments.\n"));
  if (glist_hs_length(argv) == 2)
    return (set_variable(glist_hs_get(argv, 1), hs("")));
  if (glist_hs_length(argv) == 3)
    return (set_variable(glist_hs_get(argv, 1), glist_hs_get(argv, 2)));
  else if (glist_hs_length(argv) == 1)
    {
      envcmd();
      return (1);
    }
  return (0);
}
