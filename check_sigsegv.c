/*
** checker.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu May 19 23:34:36 2016 Valentin Pichard
** Last update Thu May 26 11:45:09 2016 Valentin Pichard
*/

#include "toolbox/tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void		check_sigsegv(int status)
{
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
    fprintf(stderr, "Segmentation fault\n");
}
