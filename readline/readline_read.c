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
  int		length;
  int		read_length;

  c = egc_malloc_atomic(7);
  if ((length = read(input, c, 1)) < 1)
    return (NULL);
  c[length] = 0;
  if (c[0] == 27)
    {
      length = 1;
      if ((read_length = read(input, c + 1, 5)) < 1)
        return (NULL);
      length += read_length;
      c[length] = 0;
    }
  return (c);
}

t_hs			readline_read(t_readline *readline)
{
  struct termios	cfg;
  char         		*c;

  readline->line = hs_new_empty();
  readline_get_term(&cfg);
  readline_setup_term(&cfg);
  readline_print_prompt(readline);
  while (1)
    {
      c = read_char(readline->input);
      if (!c[0] || c[0] == '\n')
	break ;
      else if (c[0] > 0 && c[0] < 32)
        {
          if (readline_event(readline, c))
	    break ;
        }
      else
	readline_update(readline, c);
    }
  readline_restore_term(&cfg);
  egc_printf("\n");
  return (readline->line);
}
