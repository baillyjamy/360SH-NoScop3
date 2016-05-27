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

static int	errors_name(t_hs name)
{
  unsigned	i;
  char	c;

  i = 0;
  if (!char_is_alpha(hs_get(name, 0)))
    {
      fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
      return (1);
    }
  while (i < hs_length(name))
    {
      c = hs_get(name, i++);
      if (!char_is_alpha(c) || !char_is_digit(c) || c != '_')
	{
	  fprintf(stderr,
                  "setenv: Variable name must"
		  "contain alphanumeric characters.\n");
	  return (1);
	}
    }
  return (0);
}

static int	set_variable(t_hs name, t_hs value, short value_is_null)
{
  if (!errors_name(name))
    {
      if (value_is_null)
	set_env_line(name, value, 1);
      set_env_line(name, value, 0);
    }
  return (1);
}

int	setenv_cmd(t_glist_hs *argv)
{
  if (glist_hs_length(argv) > 3)
    return (egc_fprintf(STDERR_FILENO, "setenv: Too many arguments.\n"));
  if (glist_hs_length(argv) == 2)
    return (set_variable(glist_hs_get(argv, 2), hs("NULL"), 1));
  if (glist_hs_length(argv) == 3)
    return (set_variable(glist_hs_get(argv, 2), glist_hs_get(argv, 3), 0));
  else if (glist_hs_length(argv) == 1)
    {
      display_environment();
      return (1);
    }
  return (0);
}
