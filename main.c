/*
** main.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon May 30 19:08:52 2016 Pierre-Emmanuel Jacquier
** Last update Mon May 30 19:08:52 2016 Pierre-Emmanuel Jacquier
*/

#include <unistd.h>
#include <ncurses.h>
#include <term.h>
#include "sh.h"
#include "./readline/readline.h"

char	**envp;

void	bltin(t_glist_hs *args)
{
  if (hs_equals(glist_hs_get(args, 0), hs("cd")))
    cdcmd(args);
  if (hs_equals(glist_hs_get(args, 0), hs("echo")))
    echocmd(args);
  if (hs_equals(glist_hs_get(args, 0), hs("exit")))
    exitcmd(args);
  if (hs_equals(glist_hs_get(args, 0), hs("setenv")))
    setenv_cmd(args);
  if (hs_equals(glist_hs_get(args, 0), hs("env")))
    envcmd();
  if (hs_equals(glist_hs_get(args, 0), hs("unsetenv")))
    unsetenv_cmd(args);
}

int	main2(int argc, char **argv)
{
  t_hs	input;
  t_hs	user;
  t_hs	pwd;
  t_readline	*readline;
  t_statics     statics;
  t_glist_hs	args;

  statics_init(&statics);
  egc_set_statics(&statics, sizeof(t_statics));
  env_init(envp);
  while (42)
    {
      if (env_get_variable(hs("USER"), &user) == -1)
	user = hs_new_empty();
      if (env_get_variable(hs("PWD"), &pwd) == -1)
	pwd = hs_new_empty();
      setupterm(NULL, 1, NULL);
      display_prompt(user, pwd);
      readline = readline_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
      input = readline_read(readline);
      if (hs_get(input, 0) != '\0')
	{
	  args = hs_split(input, hs(" "));
	  bltin(&args);
	}
    }
  return (0);
}

int             main(int argc, char **argv, char **env)
{
  envp = env;
  return (egc_run(0, NULL, main2));
}
