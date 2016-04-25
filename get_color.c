/*
** colorize.c for 42sh in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri Apr 15 16:18:38 2016 Pierre-Emmanuel Jacquier
** Last update Mon Apr 18 16:17:32 2016 Pierre-Emmanuel Jacquier
*/

#include <string.h>
#include "colorize.h"

static void     skip_word(const char **string_pointer)
{
  while (**string_pointer)
    (*string_pointer)++;
}

int             colorize_get_color_code(const char *name)
{
  const char	*colors;
  int		i;

  i = 0;
  colors = "black\0red\0green\0yellow\0blue\0magenta\0cyan\0white\0";
  while (*colors)
    {
      if (strcmp(colors, name) == 0)
	return (i);
      skip_word(&colors);
      colors++;
      i++;
    }
  return (-1);
}
