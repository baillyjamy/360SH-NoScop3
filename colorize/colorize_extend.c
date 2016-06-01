/*
** colorize_extend.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/colorize/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Wed Jun  1 14:58:17 2016 Valentin Pichard
** Last update Wed Jun  1 14:59:24 2016 Valentin Pichard
*/

#include "private.h"

/*
** Returns 0 if a color has been read or -1 on failure
**
** `*i` is kept unchanged on failure
*/
int		read_color(t_glist_hs *words, int *i)
{
  t_hs		word;
  int           color;

  word = glist_hs_get(words, *i);
  color = colorize_get_color_code(hs_to_str(word));
  if (color != -1)
    (*i)++;
  return (color);
}

/*
** Returns 0 if the given keyword has been read or -1 on failure
**
** `*i` is kept unchanged on failure
*/
int		read_keyword(t_glist_hs *words, int *i, const char *keyword)
{
  t_hs		word;

  word = glist_hs_get(words, *i);
  if (hs_equals(word, hs(keyword)))
    {
      (*i)++;
      return (1);
    }
  else
    return (-1);
}
