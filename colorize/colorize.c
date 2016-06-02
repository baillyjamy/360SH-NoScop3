/*
** colorize.c for 42sh in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Apr 18 16:32:30 2016 Pierre-Emmanuel Jacquier
** Last update Mon Apr 18 16:32:30 2016 Pierre-Emmanuel Jacquier
*/

#include "private.h"

/*
** Returns 0 if a color has been read or -1 on failure
**
** `*i` is kept unchanged on failure
*/
static int	read_color(t_glist_hs *words, int *i)
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
static int	read_keyword(t_glist_hs *words, int *i, const char *keyword)
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

static int	parse_style(t_style *style, t_hs string)
{
  t_glist_hs	words;
  int		i;

  i = 0;
  words = hs_split(string, hs(" "));
  style->foreground = read_color(&words, &i);
  if (i >= glist_hs_length(&words))
    return (0);
  if (read_keyword(&words, &i, "on") != -1)
    {
      if (i >= glist_hs_length(&words))
        return (-1);
      style->background = read_color(&words, &i);
    }
  if (i >= glist_hs_length(&words))
    return (0);
  style->bold = read_keyword(&words, &i, "bold");
  if (i >= glist_hs_length(&words))
    return (0);
  style->underlined = read_keyword(&words, &i, "underlined");
  if (i >= glist_hs_length(&words))
    return (0);
  return (0);
}

static t_hs	format_color(int style_code)
{
  return (hs_format("\x1B[%dm", style_code));
}

static t_hs	append_color(int style_code, t_hs colorized)
{
  return (hs_concat(colorized, format_color(style_code)));
}

t_hs		colorize(const char *style_string, t_hs source)
{
  t_style	style;
  t_hs		colorized;

  style.foreground = -1;
  style.background = -1;
  style.underlined = 0;
  style.bold = 0;
  colorized = format_color(0);
  if (parse_style(&style, hs(style_string)) == -1)
    return (source);
  if (style.foreground != -1)
    colorized = append_color(style.foreground + 90, colorized);
  if (style.background != -1)
    colorized = append_color(style.background + 40, colorized);
  if (style.underlined)
    colorized = append_color(4, colorized);
  if (style.bold)
    colorized = append_color(1, colorized);
  colorized = hs_concat(colorized, source);
  colorized = hs_concat(colorized, format_color(0));
  return (colorized);
}
