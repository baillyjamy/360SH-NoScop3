/*
** cd.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Tue May 24 15:48:33 2016 Pierre-Emmanuel Jacquier
** Last update Fri May 27 02:30:24 2016 Valentin Pichard
*/

#include <unistd.h>
#include <stdio.h>
#include "../sh.h"

static int	set_current_pwd(t_hs *pwd)
{
  char		cwd[2048];

  if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
      env_set_variable(hs("PWD"), hs(cwd));
      *pwd = hs(cwd);
      return (0);
    }
  return (1);
}

static int	cd_less(void)
{
  t_hs		old_pwd;
  t_hs		current_pwd;

  if (env_get_variable(hs("OLDPWD"), &old_pwd))
    return (egc_fprintf(STDERR_FILENO, ": No such file or directory.\n"));
  set_current_pwd(&current_pwd);
  chdir(hs_to_str(old_pwd));
  env_set_variable(hs("PWD"), old_pwd);
  env_set_variable(hs("OLDPWD"), current_pwd);
  return (1);
}

static int	cd_path(t_hs path)
{
  t_hs		current_pwd;

  set_current_pwd(&current_pwd);
  if (chdir_error(path))
    return (1);
  env_set_variable(hs("OLDPWD"), current_pwd);
  env_set_variable(hs("PWD"), path);
  return (1);
}

static int	cd_home(void)
{
  t_hs		home_path;
  t_hs		current_pwd;

  set_current_pwd(&current_pwd);
  if (env_get_variable(hs("HOME"), &home_path))
    return (egc_fprintf(STDERR_FILENO, "cd: No home directory.\n"));
  else if (home_error(home_path))
    return (1);
  env_set_variable(hs("PWD"), home_path);
  env_set_variable(hs("OLDPWD"), current_pwd);
  return (1);

}

int		cdcmd(t_glist_hs *argv)
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
  else if (glist_hs_length(argv) == 1)
    return (cd_home());
  return (0);
}
