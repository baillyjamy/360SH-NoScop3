/*
** expand_variables.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri Jun  3 01:47:51 2016 Pierre-Emmanuel Jacquier
** Last update Fri Jun  3 01:47:51 2016 Pierre-Emmanuel Jacquier
*/

#include <assert.h>
#include "sh.h"

/*
** "" -> "", ""
** "euia" -> "euia", ""
** "$a" -> "", "$a"
** "bcd$a" -> "bcd", "$a"
** "$a bcd" -> "", "$a bcd"
*/
static void	skip_until_dollar(t_hs string, t_hs *before, t_hs *after)
{
  int		index;

  if ((index = hs_find_char(string, '$', 0)) == -1)
    {
      *before = string;
      *after = hs("");
      return ;
    }
  *before = hs_slice(string, 0, index);
  *after = hs_slice(string, index, hs_length(string));
}

static t_hs	get_variable_name(t_hs string)
{
  t_hs		name;
  char		c;

  name = hs("");
  while (hs_length(string))
    {
      c = hs_get(string, 0);
      if (!char_is_alpha_numeric(c))
	break ;
      string = hs_slice(string, 1, hs_length(string));
    }
  return (name);
}

static int	expand_dollar(t_hs left,
			      t_hs rigth,
			      t_hs *result)
{
  t_hs		right_result;

  if (expand_variables(left, &right_result))
    {
      *result = right_result;
      return (-1);
    }
  *result = hs_format("%hs$%hs", left, rigth);
  return (0);
}

int	expand_values(t_hs left, t_hs value, t_hs rigth, t_hs *result)
{
  t_hs	exp_right;

  if (expand_variables(rigth, &exp_right) == -1)
    {
      *result = exp_right;
      return (-1);
    }
  hs_format("%hs%hs", left, value, exp_right);
  return (0);
}

int	expand_variables(t_hs input, t_hs *result)

{
  t_hs	before;
  t_hs	after;
  t_hs	name;
  t_hs	value;

  skip_until_dollar(input, &before, &after);
  if (hs_length(after) == 0)
    {
      *result = before;
      return (0);
    }
  assert(hs_get(after, 0) == '$');
  after = hs_slice(after, 1, hs_length(after));
  name = get_variable_name(after);
  if (hs_length(name) == 0)
    return (expand_dollar(before, after, result));
  egc_printf("name = %hs", value);
  if (env_get_variable(name, &value) == -1)
    {
      *result = hs_format("%hs: Undefined variable.", name);
      return (-1);
    }
  after = hs_slice(after, hs_length(name), hs_length(after));
  return (expand_values(before, value, after, result));
}
