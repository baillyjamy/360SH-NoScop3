/*
** print.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Fri May 20 15:51:12 2016 Valentin Pichard
** Last update Thu May 26 11:41:12 2016 Valentin Pichard
*/

#include "tools.h"
#include <stdio.h>
#include <unistd.h>

void		print_string(const char *string)
{
  egc_fprintf(STDOUT_FILENO, "%s", string);
}

void		print_string_error(const char *string)
{
  egc_fprintf(STDERR_FILENO, "%s", string);
}
