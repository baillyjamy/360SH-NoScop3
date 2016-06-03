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
  if (!strcmp(c, readline->capacity->capacity_key_left)
      && readline->cursor_pos > 0)
    {
      readline->cursor_pos -= 1;
      egc_printf("%s", readline->capacity->capacity_cursor_left);
    }
  else if (!strcmp(c, readline->capacity->capacity_key_right)
	   && readline->cursor_pos < (int) hs_length(readline->line))
    {
      readline->cursor_pos += 1;
      egc_printf("%s", readline->capacity->capacity_cursor_right);
    }
}

static void	readline_ascii_event(t_capacity *capacity, char c)
{
  if (c == 0x0C)
    egc_printf("%s", capacity->capacity_clear_screen);
  else if (c == 0x04)
    {
      egc_printf("exit\n");
      exitcmd(0);
    }
  else
    return ;
}

void	readline_event(t_readline *readline, char *c)
{
  if (c[0] == 27)
    {
      readline_escape_envent(readline, c);
    }
  else
    readline_ascii_event(readline->capacity, c[0]);
}
