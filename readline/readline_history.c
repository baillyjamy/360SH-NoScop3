/*
** readline_history.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Jun  5 17:25:24 2016 Jamy Bailly
** Last update Sun Jun  5 17:25:24 2016 Jamy Bailly
*/

#include "private.h"
#include "../sh.h"

int		readline_get_history(t_readline *readline)
{
  t_glist_hs	history;

  history = glist_hs_new();
  egc_printf("YOLOLOLOLOL");
  if (get_history(&history) == -1)
    return (-1);
  egc_printf("TROLOLOL");
  egc_printf("%d", glist_hs_length(&history));
  readline->history = &history;
  readline->history_index = 0;
  return (0);
}

void		readline_history_key_up(t_readline *readline)
{
  if (glist_hs_length(readline->history) > 0)
    {
      readline->line = glist_hs_get(readline->history, readline->history_index);
      if (readline->history_index <= glist_hs_length(readline->history))
	readline->history_index += 1;
    }
}

void		readline_history_key_down(t_readline *readline)
{
  readline->line = glist_hs_get(readline->history, readline->history_index);
  if (readline->history_index > 0)
    readline->history_index -= 1;
}
