/*
** readline_get.c for  in /home/bailly_j/rendu/360SH-NoScop3/editor/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue May 24 00:32:20 2016 Jamy Bailly
** Last update Tue May 24 00:32:20 2016 Jamy Bailly
*/

#include <unistd.h>
#include "private.h"

int	readline_get_cursor_pos(t_readline *readline, int *x, int *y)
{
  struct termios	save;
  struct termios	raw;

  tcgetattr(readline->input, &save);
  raw = save;
  readline_cfmakeraw(&raw);
  if (tcsetattr(readline->input, TCSANOW, &raw) == -1)
    return (-1);
  egc_printf("\033[6n");
  if (readline_parse_cursor_position(readline->input, x, y) == -1)
    {
      egc_printf("LOFZEKA\n");
      tcsetattr(readline->input, TCSANOW, &save);
      return (-1);
    }
  tcsetattr(readline->input, TCSANOW, &save);
  return (0);
}

int	readline_get_input(t_readline *readline)
{
  return (readline->input);
}

int	readline_get_output(t_readline *readline)
{
  return (readline->output);
}

int	readline_get_error_output(t_readline *readline)
{
  return (readline->error_output);
}
