/*
** readline_char.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Mon May 30 00:25:27 2016 Jamy Bailly
** Last update Mon May 30 00:25:27 2016 Jamy Bailly
*/

#include "private.h"

void	readline_insert_char(t_readline *readline, char c)
{
  t_hs	left_hs;
  t_hs	right_hs;
  t_hs	new_line;
  t_hs  old;

  old = readline->line;
  left_hs = hs_slice(old, 0, readline->cursor_index);
  right_hs = hs_slice(old, readline->cursor_index, hs_length(old));
  new_line = hs_concat_char_hs(c, right_hs);
  egc_printf("%hs", new_line);
  readline->line = hs_concat(left_hs, new_line);
  readline->cursor_index++;
  readline->cursor_x++;
  readline_update_cursor(readline);
}

int	readline_delete_char(t_readline *readline)
{
  t_hs	left_hs;
  t_hs	right_hs;
  t_hs  old;

  if (readline->cursor_index == 0)
    return (-1);
  egc_printf("%s", readline->capacity.capacity_cursor_left);
  egc_printf("%s", readline->capacity.capacity_clr_eos);
  old = readline->line;
  left_hs = hs_slice(old, 0, readline->cursor_index - 1);
  right_hs = hs_slice(old, readline->cursor_index, hs_length(old));
  egc_printf("%hs", right_hs);
  readline->line = hs_concat(left_hs, right_hs);
  readline->cursor_index--;
  readline_update_cursor(readline);
  return (0);
}
