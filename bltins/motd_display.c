/*
** motd_display.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/bltins/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Wed Jun  8 11:56:00 2016 Valentin Pichard
** Last update Wed Jun  8 14:01:52 2016 Valentin Pichard
*/

#include <stdio.h>
#include "../sh.h"

int		motd_edit(void)
{
  printf("Just edit your .360sh-noscop3_motd "
	 "file and write your own content.\n");
  return (0);
}

static void	motd_banner(void)
{
  printf("-------------------------------------------------------------\n"
	 " __    __      _____ _    _ ____  _      _          __    __\n"
	 " \\ \\   \\ \\    / ____| |  | |___ \\| |    | |        / /   / /\n"
	 "  \\ \\   \\ \\  | (___ | |__| | __) | |    | |       / /   / /\n"
	 "   > >   > >  \\___ \\|  __  ||__ <| |    | |      < <   < <\n"
	 "  / /   / /   ____) | |  | |___) | |____| |____   \\ \\   \\ \\ \n"
	 " /_/   /_/   |_____/|_|  |_|____/|______|______|   \\_\\   \\_\\ \n"
	 "-------------------------------------------------------------\n");
}

int		motd_display(t_glist_hs *motd)
{
  int		i;

  i = 0;
  motd_banner();
  while (i < glist_hs_length(motd) - 1)
    {
      egc_printf("%hs\n", glist_hs_get(motd, i));
      i++;
    }
  return (0);
}

void		motd_display_init(void)
{
  t_glist_hs	motd;

  motd = glist_hs_new();
  get_motd_content(&motd);
  motd_display(&motd);
}
