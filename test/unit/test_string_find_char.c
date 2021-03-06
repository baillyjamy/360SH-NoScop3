/*
** test_string_find_char.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 22:03:59 2016 antoine
** Last update Sat Apr 16 13:42:28 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "test.h"

static void     test_string_find_char(void)
{
  const char    *string;

  ASSERT(string_find_char("", '\0') == NULL);
  ASSERT(string_find_char("", 'z') == NULL);
  ASSERT(string_find_char("hello", 'z') == NULL);
  string = "hello";
  ASSERT(string_find_char(string, 'h') == string);
  ASSERT(string_find_char(string, 'o') == string + 4);
}

void            test_suite_string_find_char(void)
{
  test_string_find_char();
}
