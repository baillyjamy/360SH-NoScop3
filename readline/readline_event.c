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

void	readline_ctrl_event(char c)
{
  if (c == 0x0C)
    egc_printf("%s", tigetstr("clear"));
  else
    return ;
}

void	readline_event(char *c_str, int *cursor_pos, int len_line)
{
  if (!strcmp(c_str, tigetstr("kcub1")) && *cursor_pos > 0)
    {
      *cursor_pos -= 1;
      egc_printf("%s", tigetstr("cub1"));
    }
  else if (!strcmp(c_str, tigetstr("kcuf1")) && *cursor_pos < len_line)
    {
      *cursor_pos += 1;
      egc_printf("%s", tigetstr("cuf1"));
    }
}
