/*
** char_type.c for  in /Users/pichar_v/Documents/tek1/360SH-NoScop3/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sat Apr 16 12:08:16 2016 Valentin Pichard
** Last update Sat Apr 16 12:08:26 2016 Valentin Pichard
*/

#include "char_type.h"

int     char_is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

int     char_is_uppercase(char c)
{
  return (c >= 'A' && c <= 'Z');
}

int     char_is_lowercase(char c)
{
  return (c >= 'a' && c <= 'z');
}

int     char_is_letter(char c)
{
  return (char_is_lowercase(c) || char_is_uppercase(c));
}

int     char_is_alphanumeric(char c)
{
  return (char_is_letter(c) || char_is_digit(c));
}
