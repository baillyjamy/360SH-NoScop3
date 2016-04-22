/*
** char_type_converter.c for  in /Users/pichar_v/Documents/tek1/360SH-NoScop3/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sat Apr 16 12:04:21 2016 Valentin Pichard
** Last update Sat Apr 16 12:04:40 2016 Valentin Pichard
*/

#include "char_type.h"

char    char_to_lowercase(char c)
{
  if (char_is_uppercase(c))
    return (c + ('a' - 'A'));
  return (c);
}

char    char_to_uppercase(char c)
{
  if (char_is_lowercase(c))
    return (c - ('a' - 'A'));
  return (c);
}
