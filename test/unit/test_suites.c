/*
** test_suites.c for unit in /home/antoine/42sh/test/unit
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 11 14:18:14 2016 antoine
** Last update Wed Jun 01 01:19:37 2016 Antoine Baudrand
*/

#include "test.h"

void    run_test_suites(void)
{
  test_suite_parse_int();
  test_suite_string_concat();
  test_suite_string_find();
  test_suite_string_find_char();
  test_suite_string_type();
  test_suite_string_type_convert();
  test_suite_colorize();
  test_suite_exec();
}
