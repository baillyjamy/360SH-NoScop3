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

t_hs	readline_insert_char(t_capacity *capacity,
			     t_hs line,
			     char c,
			     int *cursor_pos)
{
  t_hs	left_hs;
  t_hs	right_hs;
  t_hs	new_line;

  left_hs = hs_slice(line, 0, *cursor_pos);
  right_hs = hs_slice(line, *cursor_pos, hs_length(line));
  new_line = hs_concat_char_hs(c, right_hs);
  egc_printf("%hs", new_line);
  new_line = hs_concat(left_hs, new_line);
  *cursor_pos += 1;
  readline_update_cursor(capacity, cursor_pos, hs_length(new_line));
  return (new_line);
}

t_hs	readline_delete_char(t_capacity *capacity,
			     t_hs line,
			     int *cursor_pos)
{
  t_hs	left_hs;
  t_hs	right_hs;
  t_hs	new_line;

  egc_printf("%s", capacity->capacity_cursor_left);
  egc_printf("%s", capacity->capacity_clr_eol);
  left_hs = hs_slice(line, 0, *cursor_pos - 1);
  right_hs = hs_slice(line, *cursor_pos, hs_length(line));
  egc_printf("%hs", right_hs);
  new_line = hs_concat(left_hs, right_hs);
  *cursor_pos -= 1;
  readline_update_cursor(capacity, cursor_pos, hs_length(new_line));
  return (new_line);
}
