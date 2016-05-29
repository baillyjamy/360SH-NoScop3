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

t_hs	readline_test(t_hs line, char c, t_readline *readline)
{
  t_hs	new_line;

  if (c == '\x7f')
    {
      new_line = readline_delete_char(line, &readline->cursor_pos);
    }
  else
    {
      new_line = readline_insert_char(line, c, &readline->cursor_pos);
    }
  egc_printf("\x1b[1K\x1b[u");
  egc_printf("%hs", new_line);
  return (new_line);
}
