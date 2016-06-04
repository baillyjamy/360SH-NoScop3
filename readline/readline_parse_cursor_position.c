/*
** readline_parse_cursor_position.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Jun  5 01:30:31 2016 Jamy Bailly
** Last update Sun Jun  5 01:30:31 2016 Jamy Bailly
*/

#include <unistd.h>
#include "private.h"
#include "../parse_int/parse_int.h"

static char     read_char(int input)
{
  char          c;

  if (read(input, &c, 1) != 1)
    return ('\0');
  return (c);
}

static int      read_int_until_char(int input, char stop, int *n_pointer)
{
  t_hs          string;
  char          c;
  unsigned long n;
  int           r;

  while ((c = read_char(input)))
    {
      if (c == stop)
        break ;
      string = hs_concat_hs_char(string, stop);
    }
  if ((r = parse_uint(hs_to_str(string), &n) == 0))
    *n_pointer = n;
  return (r);
}

static int      read_chars(int input, const char *expected)
{
  if (!*expected)
    return (0);
  if (read_char(input) != *expected)
    return (-1);
  return (read_chars(input, expected + 1));
}

int     readline_parse_cursor_position(int input_fd, int *x, int *y)
{
  if (read_chars(input_fd, "\x1b["))
    return (-1);
  if (read_int_until_char(input_fd, ';', x))
    return (-1);
  return (read_int_until_char(input_fd, 'R', y));
}
