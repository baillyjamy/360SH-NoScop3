/*
** cd.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Tue May 24 15:48:33 2016 Pierre-Emmanuel Jacquier
** Last update Wed May 25 15:49:58 2016 Valentin Pichard
*/

#include <unistd.h>
#include "../egc.h"

static int	cd_less(void)
{
  t_hs	old_pwd;
  t_hs	current_pwd;

  old_pwd = get_env_line(hs("OLDPWD"));
  current_pwd = get_env_line(hs("PWD"));
  chdir(hs_to_str(old_pwd));
  set_env_line(hs_concat(hs("PWD"), old_pwd));
  set_env_line(hs_concat(hs("OLDPWD"), current_pwd));
  return (1);
}

static int	cd_path(t_hs path)
{
  t_hs		current_pwd;

  if (chdir_error(path))
    return (1);
  current_pwd = get_env_line(hs("PWD"));
  set_env_line(hs_concat(hs("OLDPWD"), current_pwd));
  set_env_line(hs_concat(hs("PWD"), path));
  return (1);
}

static int	cd_home(void)
{
  t_hs		home_path;
  t_hs		current_pwd;

  current_pwd = get_env_line(hs("PWD"));
  home_path = get_env_line(hs("HOME"));
  if (home_error(home_path))
    return (1);
  chdir(hs_to_str(home_path));
  set_env_line(hs_concat(hs("PWD"), home_path));
  set_env_line(hs_concat(hs("OLDPWD"), current_pwd));
  return (1);
}

int	cdcmd(t_glist_hs *argv)
{
  if (glist_hs_length(argv) > 2)
    return (egc_fprintf(STDERR_FILENO, "cd: Too many arguments.\n"));
  if (glist_hs_length(argv) == 2)
    {
      if (hs_equals(glist_hs_get(argv, 1), hs("-")))
	return (cd_less());
      else
	return (cd_path(glist_hs_get(argv, 1)));
    }
  else if(glist_hs_length(argv) == 1)
    return (cd_home());
  return (0);
}
