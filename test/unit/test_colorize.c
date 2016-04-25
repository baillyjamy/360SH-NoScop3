/*
** test_colorize.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 21 17:54:45 2016 antoine
** Last update Thu Apr 21 17:54:45 2016 antoine
*/

#include "test.h"
#include "colorize/colorize.h"

static void     test_comb(const char *style, t_hs string)
{
  ASSERT(hs_equals(uncolorize(colorize(style, string)), string));
}

void    test_suite_colorize(void)
{
  t_hs  s;

  s = colorize("red", hs("a"));
  ASSERT(hs_equals(s, hs("\x1B[0m" "\x1B[91m" "a" "\x1B[0m")));
  s = colorize("on red", hs("a"));
  ASSERT(hs_equals(s, hs("\x1B[0m" "\x1B[41m" "a" "\x1B[0m")));
  ASSERT(hs_equals(hs(""), uncolorize(hs(""))));
  ASSERT(hs_equals(hs("abc"), uncolorize(hs("abc"))));
  ASSERT(hs_equals(hs(""), uncolorize(hs("\x1B[0m"))));
  test_comb("red", hs("a"));
  test_comb("black on white", hs("a"));
  test_comb("underlined", hs("a"));
  test_comb("bold", hs("a"));
  test_comb("on blue underlined bold", hs("a"));
}
