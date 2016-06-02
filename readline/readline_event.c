/*
** readline_event.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Mon May 30 17:54:45 2016 Jamy Bailly
** Last update Mon May 30 17:54:45 2016 Jamy Bailly
*/

#include "private.h"
#include "string.h"

void	readline_ctrl_event(t_capacity *capacity, char c)
{
  if (c == 0x0C)
    egc_printf("%s", capacity->CAPACITY_CLEAR_SCREEN);
  else
    return ;
}

void	readline_event(t_capacity *capacity,
		       char *c_str,
		       int *cursor_pos,
		       int len_line)
{
  if (!strcmp(c_str, capacity->CAPACITY_KEY_LEFT) && *cursor_pos > 0)
    {
      *cursor_pos -= 1;
      egc_printf("%s", capacity->CAPACITY_CURSOR_LEFT);
    }
  else if (!strcmp(c_str, capacity->CAPACITY_KEY_RIGHT)
	   && *cursor_pos < len_line)
    {
      *cursor_pos += 1;
      egc_printf("%s", capacity->CAPACITY_CURSOR_RIGHT);
    }
}
