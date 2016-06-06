/*
** checker.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu May 19 23:34:36 2016 Valentin Pichard
** Last update Mon Jun  6 18:52:04 2016 Valentin Pichard
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "toolbox/tools.h"

int		check_sigsegv(int status)
{
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
    {
      egc_fprintf(STDERR_FILENO,
		  "Segmentation fault (core dumped)\n");
      return (-1);
    }
  return (0);
}
