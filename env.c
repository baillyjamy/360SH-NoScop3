/*
** env.c for 42sh in /home/antoine/42sh
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Wed May 25 16:09:49 2016 Valentin Pichard
** Last update Fri May 27 16:43:33 2016 Antoine Baudrand
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

void		set_env_line(t_hs name, t_hs value, short value_is_null)
{
  int		i;
  t_hs		line;

  (void) value_is_null;
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

void		unset_env(t_hs name)
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
      	      glist_hs_remove(&STATICS->env, i);
	    }
	}
    }
}
