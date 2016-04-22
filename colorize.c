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
  return (colorize_get_color_code(hs_to_str(word)));
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
  if (hs_equals(glist_hs_get(&words, i++), hs("on")) == 0)
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

static t_hs	format_color(int style_code)
{
  return (hs_format("\x1B[%dm", style_code));
}

static t_hs	append_color(int style_code, t_hs colorized)
{
  return (hs_concat(format_color(style_code), colorized));
}

t_hs		colorize(const char *style_string, t_hs source)
{
  t_style	style;
  t_hs		colorized;
  int		i;

  style.foreground = -1;
  style.background = -1;
  style.underlined = 0;
  style.bold = 0;
  colorized = hs_new_empty();
  i = 0;
  parse_style(&style, hs(style_string));
  if (style.foreground != -1)
    colorized = append_color((style.foreground + 30), colorized);
  if (style.background != -1)
    colorized = append_color((style.background + 40), colorized);
  if (style.underlined)
    colorized = append_color(4, colorized);
  if (style.bold)
    colorized = append_color(1, colorized);
  colorized = hs_concat(colorized, source);
  return (hs_concat(colorized, format_color(0)));
}
