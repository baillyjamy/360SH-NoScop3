/*
** string_equals.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 22:34:55 2016 antoine
** Last update Sat Apr 16 13:21:45 2016 Valentin Pichard
*/

#include "string.h"
#include "../egc.h"

int             string_equals(const char *a, const char *b)
{
  while (*a == *b)
    {
      if (!*a)
        return (1);
      a++;
      b++;
    }
  return (0);
}

int             string_equals_no_case(const char *a, const char *b)
{
  while (char_to_lower(*a) == char_to_lower(*b))
    {
      if (!*a)
        return (1);
      a++;
      b++;
    }
  return (0);
}
