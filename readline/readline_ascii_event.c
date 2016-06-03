/*
** readline_ascii_event.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Fri Jun  3 18:23:09 2016 Jamy Bailly
** Last update Fri Jun  3 18:23:09 2016 Jamy Bailly
*/

#include "private.h"

static void	init_event_function(t_readline_ascii *event_ptr)
{
  event_ptr[0] = &readline_ctrl_d;
  event_ptr[1] = &readline_ctrl_l;
}

static void	init_event_list(int *event_list)
{
  event_list[0] = 0x04;
  event_list[1] = 0x0C;
}

int			readline_ascii_event(t_readline *readline, char c)
{
  int			event_list[9];
  t_readline_ascii	event_ptr[9];
  int			i;

  i = 0;
  init_event_list(event_list);
  init_event_function(event_ptr);
  while (i < 2)
    {
      if (c == event_list[i])
	return (event_ptr[i](readline));
      i++;
    }
    return (0);
}
