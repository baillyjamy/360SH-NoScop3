/*
** readline_read.c for  in /home/bailly_j/rendu/360SH-NoScop3/editor/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed May 25 15:34:49 2016 Jamy Bailly
** Last update Wed May 25 15:34:49 2016 Jamy Bailly
*/

#include <unistd.h>
#include "private.h"

static char     *read_char(int input)
{
  char          *c;
  int		lim;

  c = egc_malloc(7);
  if ((lim = read(input, c, 6)) < 1)
    return (NULL);
  c[lim] = 0;
  return (c);
}

t_hs			readline_read(t_readline *readline)
{
  struct termios	cfg;
  t_hs         		line;
  char         		*c_str;
  char			c;

  line = hs_new_empty();
  readline_get_term(&cfg);
  readline_setup_term(cfg);
  readline_print_prompt(readline);
  while (1)
    {
      c_str = read_char(readline_get_input(readline));
      c = c_str[0];
      if (!c || c == '\n' || c == 0x0C)
	{
	  readline_ctrl_event(RDC, c);
	  break ;
	}
      if (c == 27)
	readline_event(RDC, c_str, &readline->cursor_pos, hs_length(line));
      else
	line = readline_update(RDC, line, c, &readline->cursor_pos);
    }
  readline_restore_term(&cfg);
  egc_printf("\n");
  return (line);
}
