/*
** print.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Fri May 20 15:51:12 2016 Valentin Pichard
** Last update Fri May 20 16:08:18 2016 Valentin Pichard
*/

#include "tools.h"
#include <stdio.h>

void		print_string(const char *string)
{
  fprintf(stdout, "%s", string);
}

void		print_string_error(const char *string)
{
  fprintf(stderr, "%s", string);
}
