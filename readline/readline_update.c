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

void	readline_update_cursor(const t_readline *readline)
{
  int	new_pos;

  new_pos = hs_length(readline->line);
  while (new_pos != readline->cursor_pos)
    {
      egc_printf("%s", readline->capacity.capacity_cursor_left);
      new_pos--;
    }
}

void	readline_update(t_readline *readline, char *c)
{
  int	i;

  i = -1;
  while (c[++i])
    {
      if (c[i] == '\x7f')
	readline_delete_char(readline);
      else
	readline_insert_char(readline, c[i]);
    }
}
