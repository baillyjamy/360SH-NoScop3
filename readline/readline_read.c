/*
** readline_read.c for readline in /home/antoine/360SH-NoScop3/readline
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed May 25 15:34:49 2016 Jamy Bailly
** Last update Thu Jun 02 22:55:49 2016 Antoine Baudrand
*/

#include <unistd.h>
#include "private.h"

static char     *read_char(int input)
{
  char          *c;
  int		lim;

  c = egc_malloc_atomic(7);
  if ((lim = read(input, c, 1)) < 1)
    return (NULL);
  c[lim] = 0;
  if (c[0] == 27)
    {
      if ((lim += read(input, (c + 1), 5)) < 1)
        return (NULL);
      c[lim] = 0;
    }
  return (c);
}

t_hs			readline_read(t_readline *readline)
{
  struct termios	cfg;
  char         		*c_str;
  char			c;
  int			i;

  readline->line = hs_new_empty();
  readline_get_term(&cfg);
  readline_setup_term(cfg);
  readline_print_prompt(readline);
  while (1)
    {
      c_str = read_char(readline->input);
      c = c_str[0];
      if (!c || c == '\n' || c == 0x0C)
	{
	  readline_ctrl_event(readline->capacity, c);
	  break ;
	}
      if (c == 27)
	readline_event(readline->capacity, c_str, &readline->cursor_pos,
                       hs_length(readline->line));
      else
	{
	  i = -1;
	  while (c_str[++i])
	    readline_update(readline, c_str[i]);
	}
    }
  readline_restore_term(&cfg);
  egc_printf("\n");
  return (readline->line);
}
