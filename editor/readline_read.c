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
#include "readline.h"

static char     read_char(int input)
{
  char          c;

  if (read(input, &c, 1) != 1)
    return ('\0');
  return (c);
}

t_hs			readline_read(t_readline *readline)
{
  t_hs                  line;
  char                  c;
  struct termios        cfg;

  line = hs_new_empty();
  readline_get_term(&cfg);
  readline_setup_term(cfg);
  while (1)
    {
      c = read_char(readline_get_input(readline));
      if (!c || c == '\n')
	break ;
      line = hs_concat_hs_char(line, c);
    }
  readline_restore_term(&cfg);
  return (line);
}
