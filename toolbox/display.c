/*
** display.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Thu May 19 23:13:05 2016 Valentin Pichard
** Last update Thu May 26 18:44:22 2016 Valentin Pichard
*/

#include "tools.h"
#include <unistd.h>
#include "../sh.h"
#include "../colorize/private.h"

void		display_environment(void)
{
  int		i;

  i = 0;
  while (i < glist_hs_length(&STATICS->env))
    egc_printf("%hs", glist_hs_get(&STATICS->env, i++));
}

void		display_prompt(const char *user, const char *host)
{
  egc_fprintf(STDOUT_FILENO, "%s%s%s@%s ~ $ ", FG_RED, user, RESET, host);
}
