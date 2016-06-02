/*
** readline_test.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun May 29 21:06:42 2016 Jamy Bailly
** Last update Sun May 29 21:06:42 2016 Jamy Bailly
*/

#include <stdio.h>
#include <unistd.h>
#include "private.h"

void	readline_update_cursor(t_capacity *capacity,
			       int *cursor_pos,
			       size_t len_line)
{
  int	new_pos;

  new_pos = len_line;
  while (new_pos != *cursor_pos)
    {
      egc_printf("%s", capacity->CAPACITY_CURSOR_LEFT);
      new_pos--;
    }
}

t_hs	readline_update(t_capacity *capacity,
			t_hs line,
			char c,
			int *cursor_pos)
{
  t_hs	new_line;

  if (c == '\x7f')
    new_line = readline_delete_char(capacity, line, cursor_pos);
  else
    new_line = readline_insert_char(capacity, line, c, cursor_pos);
  return (new_line);
}
