/*
** display.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu May 19 23:13:05 2016 Valentin Pichard
** Last update Fri May 20 15:54:53 2016 Valentin Pichard
*/

#include "sh.h"
#include <stdio.h>
#include "colorize/colorize.h"

void		display_environment(const char **envp)
{
  int		i;

  i = 0;
  while (envp[i])
    fprintf(stdout, "%s\n", envp[i]);
}

void		display_prompt(const char *user)
{
  fprintf(stdout, "%s%s%s@360SH-NoScop3 ~ $ ", FG_RED, user, RESET);
}
