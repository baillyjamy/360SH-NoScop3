/*
** colorize_private.h for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Apr 18 17:27:06 2016 Pierre-Emmanuel Jacquier
** Last update Mon Apr 18 17:27:06 2016 Pierre-Emmanuel Jacquier
*/

#ifndef COLORIZE_PRIVATE_H
# define COLORIZE_PRIVATE_H

# include "colorize.h"

typedef struct
{
  int foreground; // -1
  int background;
  int underlined;
  int bold;
} t_style;

/*
"on blue"
{-1, blue, 0, 0}

"undelined"
{-1, -1, 1, 0};

"green on cyan bold"
{green, pink, 0, 1};
*/

int		colorize_get_color_code(const char *name);

#endif /* COLORIZE_PRIVATE_H */
