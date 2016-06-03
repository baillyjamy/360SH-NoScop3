/*
** test_expand_variables.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/test/unit/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri Jun  3 21:20:26 2016 Pierre-Emmanuel Jacquier
** Last update Fri Jun  3 21:20:26 2016 Pierre-Emmanuel Jacquier
*/

#include "test.h"

void	test_expand_variables(void)
{
  t_hs	result;
  t_hs	variable;

  result = hs("");
  expand_variables(hs(""), &result);
  ASSERT(hs_equals(result, hs("")));
  result = hs("");
  expand_variables(hs("momo$TAMERE  hello"), &result);
  ASSERT(hs_equals(result, hs("momo$TAMERE  hello")));
  result = hs("");
  variable = hs("");
  env_get_variable(hs("HOME"), &variable);
  expand_variables(hs("$HOME"), &result);
  ASSERT(hs_equals(result, variable));
}
