/*
** colorize.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 14 11:47:15 2016 antoine
** Last update Thu May 19 23:21:22 2016 Valentin Pichard
*/

#ifndef COLORIZE_H
# define COLORIZE_H

# include "../egc.h"

#  define FG_BLACK "\x1b[90m"
#  define FG_GREEN "\x1b[92m"
#  define FG_RED "\x1b[91m"
#  define FG_WHITE "\x1b[97m"
#  define BG_WHITE "\x1b[107m"
#  define BG_GREEN "\x1b[102m"
#  define BG_RED "\x1b[101m"
#  define BG_BLACK "\x1b[100m"
#  define RESET "\x1b[0m"

t_hs	uncolorize(t_hs source);

/*
** A bit like the colorize gem (https://github.com/fazibear/colorize)
**
** Examples:
**
**     hs_puts(colorize_str("green", "This text is green"));
**     hs_puts("This text is normal");
**     hs_puts(colorize_str("red on blue", "This text is red on blue"));
**     hs_puts(colorize_str("pink underlined",
**                          "This text is pink and underlined"));
*/

t_hs	colorize(const char *style, t_hs source);


#endif /* COLORIZE_H */
