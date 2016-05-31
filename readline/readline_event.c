/*
** readline_event.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Mon May 30 17:54:45 2016 Jamy Bailly
** Last update Mon May 30 17:54:45 2016 Jamy Bailly
*/

#include <ncurses.h>
#include "readline.h"

#include "string.h"

void	readline_event(char *c_str)
{
  if (!strcmp(c_str, tigetstr("kcub1")))
    egc_printf("\nKEY LEFT !");
  else if (!strcmp(c_str, tigetstr("kcuf1")))
    egc_printf("\nKEY RIGHT\n");
}
