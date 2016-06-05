/*
** readline_history.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Jun  5 17:25:24 2016 Jamy Bailly
** Last update Sun Jun  5 21:12:26 2016 Valentin Pichard
*/

#include "private.h"
#include "../sh.h"

int		readline_get_history(t_readline *readline)
{
  t_glist_hs	history;
  t_hs		path;

  history = glist_hs_new();
  path = path_history();
  if (get_file_content(path, &history) == -1)
    return (-1);
  readline->history = history;
  readline->history_index = 0;
  return (0);
}

void		readline_history_key_up(t_readline *readline)
{
  t_hs		history_up;
  int		history_length;
  int		g_index;
  int		i;
  char		*c;

  i = 0;
  history_length = glist_hs_length(&readline->history);
  if (history_length > 0)
    {
      g_index = history_length - 2 - readline->history_index;
      history_up = glist_hs_get(&readline->history, g_index);
      if (readline->history_index + 2 < history_length)
	readline->history_index += 1;
      while (!readline_delete_char(readline))
	;
      while (i < (int)hs_length(history_up))
	{
	  c = hs_to_str(hs_new_from_char(hs_get(history_up, i)));
	  readline_update(readline, c);
	  i++;
	}
    }
}

void		readline_history_key_down(t_readline *readline)
{
  t_hs		history_up;
  int		history_length;
  int		g_index;
  int		i;
  char		*c;

  i = 0;
  history_length = glist_hs_length(&readline->history);
  if (history_length > 0)
    {
      g_index = history_length - readline->history_index;
      history_up = glist_hs_get(&readline->history, g_index);
      if (readline->history_index > 0)
	readline->history_index -= 1;
      while (!readline_delete_char(readline));
      while (i < (int)hs_length(history_up))
	{
	  c = hs_to_str(hs_new_from_char(hs_get(history_up, i)));
	  readline_update(readline, c);
	  i++;
	}
    }
}
