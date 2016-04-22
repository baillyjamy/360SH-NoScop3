/*
** uncolorize.c for 42sh in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Apr 21 21:36:33 2016 Pierre-Emmanuel Jacquier
** Last update Thu Apr 21 21:36:33 2016 Pierre-Emmanuel Jacquier
*/

#include "colorize.h"

t_hs	uncolorize(t_hs s)
{
  int	code_start;
  int	code_end;
  t_hs	left;
  t_hs	right;

  while (1)
    {
      code_start = hs_find(s, hs("\x1B["), 0);
      if (code_start == -1)
	break;
      code_end = hs_find_char(s, 'm', code_start);
      left = hs_slice(s, 0, code_start);
      right = hs_slice(s, code_end, hs_length(s));
      s = hs_concat(left, right);
    }
  return (s);
}
