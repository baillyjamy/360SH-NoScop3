/*
** echo.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Sat May 28 19:39:43 2016 Pierre-Emmanuel Jacquier
** Last update Sat May 28 19:39:43 2016 Pierre-Emmanuel Jacquier
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
      if (i < glist_hs_length(argv) - 1)
	egc_printf("%hs ", glist_hs_get(argv, i));
      else if (i < glist_hs_length(argv))
	egc_printf("%hs", glist_hs_get(argv, i));
      i++;
    }
  if (!hs_equals(glist_hs_get(argv, 1), hs("-n")))
    egc_printf("\n");
  return (1);
}

int	echocmd(t_glist_hs *argv)
{
  if (glist_hs_length(argv) == 1)
    return(egc_printf("\n"));
  else if (glist_hs_length(argv) > 1)
    return (print_args(argv));
  return (0);
}
