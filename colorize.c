/*
** colorize.c for 42sh in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Apr 18 16:32:30 2016 Pierre-Emmanuel Jacquier
** Last update Mon Apr 18 16:32:30 2016 Pierre-Emmanuel Jacquier
*/

#include "colorize_private.h"

static int	parse_color(t_glist_hs *words, int *i)
{
  t_hs		word;

  if (*i >= glist_hs_length(words))
    return (-1);
  word = glist_hs_get(words, *i);
  (*i)++;
  /* TODO: remove this piece of crap */
  return (get_color_code(word._chars));
}

static int	parse_keyword(t_glist_hs *words, int *i, const char *keyword)
{
  t_hs		word;

  if (*i >= glist_hs_length(words))
    return (-1);
  word = glist_hs_get(words, *i);
  (*i)++;
  if (hs_equals(word, hs(keyword)))
    return (1);
  return (0);
}

static int	parse_style(t_style *style, t_hs string)
{
  t_glist_hs	words;
  int		i;

  i = 0;
  words = hs_split(string, hs(" "));
  if ((style->foreground = parse_color(&words, &i)) == -1)
    return (-1);
  if (i >= glist_hs_length(&words))
    return (-1);
  if (hs_equals(glist_hs_get(&words, i++), i), hs("on") == 0)
    {
      if ((style->background = parse_color(&words, &i)) == -1)
	return (-1);
    }
  if (i >= glist_hs_length(&words))
    return (-1);
  if ((style->underlined = parse_keyword(&words, &i, "underlined")) == -1)
    return (-1);
  if (i >= glist_hs_length(&words))
    return (-1);
  if ((style->bold = parse_keyword(&words, &i, "bold")) == -1)
    return (-1);
  if (i >= glist_hs_length(&words))
    return (-1);
  return (0);
}

t_hs		colorize_hs(const char *color_name, t_hs source)
{
  t_glist_hs	words;
  int		i;

  i = 0;
  words = hs_split(source, hs(" "));
  while (i < glist_hs_length(&words))
    {
      egc_printf("%hs\n", glist_hs_get(&words, i));
    }
  return (source);
}
