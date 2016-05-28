/*
** private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri May 20 23:03:21 2016 antoine
** Last update Fri May 20 23:03:21 2016 antoine
*/

#ifndef COLORIZE_PRIVATE_H
# define COLORIZE_PRIVATE_H

# include "colorize.h"

# define FG_BLACK "\x1b[90m"
# define FG_GREEN "\x1b[92m"
# define FG_RED "\x1b[91m"
# define FG_WHITE "\x1b[97m"
# define BG_WHITE "\x1b[107m"
# define BG_GREEN "\x1b[102m"
# define BG_RED "\x1b[101m"
# define BG_BLACK "\x1b[100m"
# define RESET "\x1b[0m"

/*
** foregroud and backgroud defaults to -1.
*/
typedef struct  s_style
{
  int           foreground;
  int           background;
  int           underlined;
  int           bold;
}               t_style;

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
