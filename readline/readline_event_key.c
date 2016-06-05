/*
** readline_event_key.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Jun  5 17:00:12 2016 Jamy Bailly
** Last update Sun Jun  5 17:00:12 2016 Jamy Bailly
*/

#include "private.h"

int	readline_key_home(t_readline *readline)
{
  readline->cursor_index = 0;
  egc_printf("%s", readline->capacity.capacity_cursor_home);
  return (0);
}
