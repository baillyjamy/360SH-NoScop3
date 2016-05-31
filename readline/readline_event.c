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

void	readline_event(char *c_str, int *cursor_pos)
{
  if (!strcmp(c_str, tigetstr("kcub1")))
    {
      *cursor_pos -= 1;
      egc_printf("%s", tigetstr("cub1"));
      egc_printf("%s", tigetstr("sc"));
    }
  else if (!strcmp(c_str, tigetstr("kcuf1")))
    {
      *cursor_pos += 1;
      egc_printf("%s", tigetstr("cuf1"));
      egc_printf("%s", tigetstr("sc"));
    }
}
