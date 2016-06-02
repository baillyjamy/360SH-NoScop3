/*
** readline.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 18 08:57:08 2016 antoine
** Last update Sat Apr 30 06:38:25 2016 Jamy Bailly
*/

#include <ncurses.h>
#include "private.h"

t_capacity	*readline_new_capacity(void)
{
  t_capacity	*capacity;

  capacity = egc_malloc(sizeof(t_capacity));
  capacity->CAPACITY_CLEAR_SCREEN = tigetstr("CAPACITY_CLEAR_SCREEN");
  capacity->CAPACITY_KEY_LEFT = tigetstr("CAPACITY_KEY_LEFT");
  capacity->CAPACITY_KEY_RIGHT = tigetstr("CAPACITY_KEY_RIGHT");
  capacity->CAPACITY_CURSOR_LEFT = tigetstr("CAPACITY_CURSOR_LEFT");
  capacity->CAPACITY_CURSOR_RIGHT = tigetstr("CAPACITY_CURSOR_RIGHT");
  capacity->CAPACITY_CLR_EOL = tigetstr("CAPACITY_CLR_EOL");
  return (capacity);
}

t_readline      *readline_new(int input, int output, int error_output)
{
  t_readline    *readline;

  readline = egc_malloc(sizeof(t_readline));
  readline->input = input;
  readline->output = output;
  readline->error_output = error_output;
  readline->cursor_pos = 0;
  readline->prompt = hs_new_empty();
  readline->capacity = readline_new_capacity();
  return (readline);
}
