/*
** read_string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Jun  4 16:14:48 2016 antoine
** Last update Sat Jun  4 16:14:48 2016 antoine
*/

#include "private.h"

int             lexer_read_string(const char *exp, const char **string_p)
{
  const char    *begin;

  begin = *string_p;
  while (**string_p == *exp)
    {
      if (!*exp)
        break ;
      NEXT(string_p);
      NEXT(&exp);
    }
  if (*exp)
    {
      *string_p = begin;
      return (0);
    }
  return (1);
}
