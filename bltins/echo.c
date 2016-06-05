/*
** echo.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Sat May 28 19:39:43 2016 Pierre-Emmanuel Jacquier
** Last update Wed Jun  1 14:57:41 2016 Valentin Pichard
*/

#include "../sh.h"

static int	print_args(t_glist_hs *argv)
{
  int	i;

  i = 1;
  if (hs_equals(glist_hs_get(argv, 1), hs("-n")))
    i = 2;
  while (i < glist_hs_length(argv))
    {
      hs_print_file(glist_hs_get(argv, i), STATICS->out);
      if (i != glist_hs_length(argv) - 1)
	egc_fprintf(STATICS->out, " ");
      i++;
    }
  if (!hs_equals(glist_hs_get(argv, 1), hs("-n")))
    hs_print_file(hs("\n"), STATICS->out);
  return (0);
}

int	echo_cmd(t_glist_hs *argv)
{
  if (glist_hs_length(argv) == 1)
    {
      egc_fprintf(STATICS->out, "\n");
      return (0);
    }
  else if (glist_hs_length(argv) > 1)
    return (print_args(argv));
  return (0);
}
