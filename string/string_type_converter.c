/*
** string_type_converter.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri May 27 23:02:58 2016 antoine
** Last update Fri May 27 23:02:58 2016 antoine
*/

#include <stddef.h>
#include "string_type.h"
#include "../egc.h"
#include "string.h"

char            *string_to_lowercase(const char *source)
{
  char          *copy;
  size_t        i;

  copy = string_duplicate(source);
  i = 0;
  while (source[i])
    {
      copy[i] = char_to_lower(source[i]);
      i++;
    }
  return (copy);
}

char            *string_to_uppercase(const char *source)
{
  char          *copy;
  size_t        i;

  copy = string_duplicate(source);
  i = 0;
  while (source[i])
    {
      copy[i] = char_to_upper(source[i]);
      i++;
    }
  return (copy);
}
