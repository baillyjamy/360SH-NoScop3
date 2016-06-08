/*
** motd.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/bltins/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon Jun  6 20:40:45 2016 Valentin Pichard
** Last update Wed Jun  8 13:53:37 2016 Valentin Pichard
*/

#include "../sh.h"

static int	motd_usage(void)
{
  egc_printf("Usage : motd\n\n"
	     "\tdisplay - Show MOTD\n"
	     "\tedit - See how to edit MOTD\n");
  return (0);
}

int		get_motd_content(t_glist_hs *motd)
{
  t_hs		path;
  int		create;

  create = 0;
  path = path_motd();
  if (!file_exist(path))
    create++;
  if (get_file_content(path, motd) == -1)
    return (-1);
  if (create)
    insert_line(path,
		hs("ON\nDON'T DELETE PREVIOUS LINES\n"
		   "------------------\n"
		   "Write content just below:"));
  return (0);
}

int		motd_cmd(t_glist_hs *argv)
{
  t_hs		arg;
  t_glist_hs	motd;

  motd = glist_hs_new();
  if (hs_length(glist_hs_get(argv, 1)) > 1)
    arg = glist_hs_get(argv, 1);
  else
    return (motd_usage());
  if (hs_equals(arg, hs("edit")))
    return (motd_edit());
  if (hs_equals(arg, hs("display")))
    return (motd_display(&motd));
  motd_usage();
  return (0);
}
