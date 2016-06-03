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

static void     test_empty()
{
  t_hs          result;

  ASSERT(expand_variables(hs(""), &result) == 0);
  ASSERT(hs_equals(result, hs("")));
}

static void     test_no_vars()
{
  t_hs          result;

  ASSERT(expand_variables(hs("hi $ no variables here"), &result) == 0);
  ASSERT(hs_equals(result, hs("hi $ no variables here")));
}

static void     test_env()
{
  t_hs          result;

  ASSERT(env_get_variable(hs("unknown_variable"), &result) == -1);
  env_set_variable(hs("test_variable"), hs("hello"));
  ASSERT(env_get_variable(hs("test_variable"), &result) == 0);
  ASSERT(hs_equals(result, hs("hello")));
}

void	test_suite_expand_variables(void)
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
  test_env();
  test_empty();
  test_no_vars();
  env_set_variable(hs("test_variable"), hs("hello"));
  ASSERT(expand_variables(hs("$test_variable world"), &result) == 0);
  ASSERT(hs_equals(result, hs("hello world")));
}
