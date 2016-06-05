/*
** readline.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 18 08:57:08 2016 antoine
** Last update Sat Apr 30 06:38:25 2016 Jamy Bailly
*/

#include <term.h>
#include <string.h>
#include "private.h"

void    readline_init_capacity(t_capacity *capacity)
{
  capacity->capacity_clear_screen = tigetstr("clear");
  capacity->capacity_key_left = tigetstr("kcub1");
  capacity->capacity_key_right = tigetstr("kcuf1");
  capacity->capacity_key_up = tigetstr("kcuu1");
  capacity->capacity_key_down = tigetstr("kcud1");
  capacity->capacity_cursor_left = tigetstr("cub1");
  capacity->capacity_cursor_right = tigetstr("cuf1");
  capacity->capacity_cursor_up = tigetstr("cuu1");
  capacity->capacity_cursor_down = tigetstr("cud1");
  capacity->capacity_cursor_end = tigetstr("hpa");
  capacity->capacity_clr_eol = tigetstr("el");
  capacity->capacity_clr_eos = tigetstr("ed");
  capacity->capacity_cursor_home = tigetstr("home");
}

t_readline      *readline_new(int input, int output, int error_output)
{
  t_readline    *readline;

  readline = EGC_NEW(t_readline);
  readline->input = input;
  readline->output = output;
  readline->error_output = error_output;
  readline->prompt = hs_new_empty();
  return (readline);
}
