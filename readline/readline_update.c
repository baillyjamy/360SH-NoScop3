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
#include <ncurses.h>
#include "private.h"

t_hs	readline_update(t_hs line, char c, int *cursor_pos)
{
  t_hs	new_line;

  if (c == '\x7f')
    new_line = readline_delete_char(line, cursor_pos);
  else
    new_line = readline_insert_char(line, c, cursor_pos);
  egc_printf("\x1b[1K\x1b[1G");
  egc_printf("%hs", new_line);
  egc_printf("%s", tigetstr("rc"));
  return (new_line);
}
