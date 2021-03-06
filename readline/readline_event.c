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
#include "../sh.h"

static void	readline_escape_envent(t_readline *readline, char *c)
{
  if (!strcmp(c, readline->capacity.capacity_key_left)
      && readline->cursor_index > 0)
    {
      readline->cursor_index -= 1;
      egc_printf("%s", readline->capacity.capacity_cursor_left);
    }
  else if (!strcmp(c, readline->capacity.capacity_key_right)
	   && readline->cursor_index < (int) hs_length(readline->line))
    {
      readline->cursor_index += 1;
      egc_printf("%s", readline->capacity.capacity_cursor_right);
    }
  else if (!strcmp(c, readline->capacity.capacity_key_up))
    readline_history_key_up(readline);
  else if (!strcmp(c, readline->capacity.capacity_key_down))
    readline_history_key_down(readline);
}

int     readline_event(t_readline *readline, char *c)
{
  if (c[0] == 27)
    readline_escape_envent(readline, c);
  else if (readline_ascii_event(readline, c[0]) && !hs_length(readline->line))
    return (-1);
  return (0);
}
