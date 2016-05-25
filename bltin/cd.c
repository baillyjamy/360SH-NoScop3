/*
** cd.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Tue May 24 15:48:33 2016 Pierre-Emmanuel Jacquier
** Last update Wed May 25 15:49:58 2016 Valentin Pichard
*/

#include "../egc.h"

int	cdcmd(t_glist_hs *argv)
{
  if (glist_hs_length(argv) == 2)
    {
      if (hs_equals(glist_hs_get(args, 0), hs("-")))
	return (cd_less());
      else
	return (cd_path());
    }
  else if(glist_hs_length(argv) == 1)
    return (cd_home());
  return (0);
}
