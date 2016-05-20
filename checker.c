/*
** checker.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu May 19 23:34:36 2016 Valentin Pichard
** Last update Fri May 20 16:02:29 2016 Valentin Pichard
*/

#include "sh.h"
#include <stdlib.h>
#include <stdio.h>

void		check_segfault(const int status)
{
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
    fprintf(stderr, "Segmentation fault\n");
}
