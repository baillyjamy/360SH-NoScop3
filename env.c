/*
** get_env.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Wed May 25 16:09:49 2016 Valentin Pichard
** Last update Fri May 27 00:17:25 2016 Valentin Pichard
*/

#include "sh.h"

void		get_env(const char **envp)
{
  STATICS->env = glist_hs_new();
  while (*envp)
    {
      glist_hs_append(&STATICS->env, hs(*envp));
      envp++;
    }
}

int		get_env_line(t_hs name, t_hs *value)
{
  int		i;
  t_hs		line;

  i = 0;
  while (i < glist_hs_length(&STATICS->env))
    {
      line = glist_hs_get(&STATICS->env, i++);
      if (hs_starts_with(line, hs_concat_hs_char(name, '=')))
	{
	  *value = hs_slice(line, hs_length(name) + 1, hs_length(line));
	  return (0);
	}
    }
  return (-1);
}

static int	env_variable_exists(t_hs name)
{
  t_hs		lel;

  return (get_env_line(name, &lel) == 0);
}

static void	env_variable_creator(t_hs name, t_hs value)
{
  glist_hs_append(&STATICS->env,
		  hs_concat(hs_concat_hs_char(name, '='),
			    value));
}

void		set_env_line(t_hs name, t_hs value)
{
  int		i;
  t_hs		line;

  i = 0;
  if (env_variable_exists(name))
    {
      while (i < glist_hs_length(&STATICS->env))
	{
	  line = glist_hs_get(&STATICS->env, i++);
	  if (hs_starts_with(line, hs_concat_hs_char(name, '=')))
	    {
	      glist_hs_set(&STATICS->env,
			   i,
			   hs_concat(hs_concat_hs_char(name, '='), value));
	    }
	}
    }
  else
    env_variable_creator(name, value);
}
