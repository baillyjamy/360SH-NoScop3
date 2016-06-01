/*
** colorize_extend.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Jun  1 16:21:06 2016 antoine
** Last update Wed Jun  1 16:21:06 2016 antoine
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
