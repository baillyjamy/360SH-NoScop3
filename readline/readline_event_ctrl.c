/*
** readline_event_ctrl.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Fri Jun  3 19:13:08 2016 Jamy Bailly
** Last update Fri Jun  3 19:13:08 2016 Jamy Bailly
*/

#include "private.h"
#include "../sh.h"

int	readline_ctrl_d(t_readline *readline)
{
  (void) readline;
  return (-1);
}

int	readline_ctrl_l(t_readline *readline)
{
  egc_printf("%s", readline->capacity.capacity_clear_screen);
  return (0);
}
