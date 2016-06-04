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

/*
** Reads a character from the standard input
**
** If the EOF is reach or an error occured, '\0' is returned.
*/
static char     read_char_raw(int input)
{
  char          c;

  if (read(input, &c, 1) != 1)
    return ('\0');
  return (c);
}

/*
** Reads a line from the standard input
**
** The line is terminated by a Ctrl+D or a '\n'.
*/
static t_hs     readline_raw(t_readline *readline)
{
  t_hs          line;
  char          c;

  line = hs_new_empty();
  while (1)
    {
      c = read_char_raw(readline->input);
      if (!c && !hs_length(line))
        return (hs("exit"));
      if (!c || c == '\n')
        break ;
      line = hs_concat_hs_char(line, c);
    }
  return (line);
}

t_hs			readline_read(t_readline *readline)
{
  struct termios	cfg;
  char         		*c;

  if (!isatty(readline->input) || readline_get_term(&cfg))
    return (readline_raw(readline));
  readline->line = hs_new_empty();
  readline_setup_term(readline->output, &cfg);
  readline_print_prompt(readline);
  while (1)
    {
      c = read_char(readline->input);
      if (!c || !c[0] || c[0] == '\n')
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
