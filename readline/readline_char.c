/*
** readline_char.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Mon May 30 00:25:27 2016 Jamy Bailly
** Last update Mon May 30 00:25:27 2016 Jamy Bailly
*/

#include "readline.h"

t_hs	readline_insert_char(t_hs line, char c, int *cursor_pos)
{
  t_hs	left_hs;
  t_hs	right_hs;
  t_hs	new_line;

  left_hs = hs_slice(line, 0, *cursor_pos);
  right_hs = hs_slice(line, *cursor_pos, hs_length(line));
  new_line = hs_concat_hs_char(left_hs, c);
  new_line = hs_concat(new_line, right_hs);
  *cursor_pos += 1;
  return (new_line);
}

t_hs	readline_delete_char(t_hs line, int *cursor_pos)
{
  t_hs	left_hs;
  t_hs	right_hs;
  t_hs	new_line;

  left_hs = hs_slice(line, 0, *cursor_pos - 1);
  right_hs = hs_slice(line, *cursor_pos + 1, hs_length(line));
  new_line = hs_concat(left_hs, right_hs);
  *cursor_pos -= 1;
  return (new_line);
}
