/*
** test_expand_variables.c for unit in /home/antoine/360SH-NoScop3/test/unit
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Jun  4 14:56:23 2016 antoine
** Last update Sat Jun 04 19:10:59 2016 Antoine Baudrand
*/

#include "test.h"

static void     test_env()
{
  t_hs          result;

  ASSERT(env_get_variable(hs("unknown_variable"), &result) == -1);
  env_set_variable(hs("test_variable"), hs("hello"));
  ASSERT(env_get_variable(hs("test_variable"), &result) == 0);
  ASSERT(hs_equals(result, hs("hello")));
}

static void     test_empty()
{
  t_hs          result;

  ASSERT(expand_variables(hs(""), &result) == 0);
  ASSERT(hs_equals(result, hs("")));
}

static void     test_no_vars_unknown()
{
  t_hs          result;

  ASSERT(expand_variables(hs("hi $ no variables here"), &result) == 0);
  ASSERT(hs_equals(result, hs("hi $ no variables here")));
  ASSERT(expand_variables(hs("$unknown_variable"), &result) == -1);
  ASSERT(hs_equals(result, hs("unknown_variable: Undefined variable.")));
}

static void     test_var()
{
  t_hs          result;

  env_set_variable(hs("test_variable"), hs("hello"));
  ASSERT(expand_variables(hs("$test_variable world"), &result) == 0);
  ASSERT(hs_equals(result, hs("hello world")));
}

void	test_suite_expand_variables(void)
{
  test_env();
  test_empty();
  test_no_vars_unknown();
  test_var();
}
