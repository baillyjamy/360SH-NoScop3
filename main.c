/*
** main.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon May 30 19:08:52 2016 Pierre-Emmanuel Jacquier
** Last update Mon May 30 19:08:52 2016 Pierre-Emmanuel Jacquier
*/

#include "sh.h"
#include <unistd.h>
#include <ncurses.h>
#include <term.h>

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

int		launch(int argc, char **argv, char **env)
{
  t_hs		input;
  t_readline	*readline;
  t_statics     statics;
  t_glist_hs	args;

  (void) argc;
  (void) argv;
  statics_init(&statics);
  egc_set_statics(&statics, sizeof(t_statics));
  env_init(env);
  while (1)
    {
      readline = readline_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
      readline_set_prompt(readline, create_prompt());
      input = readline_read(readline);
      egc_printf("Return = %hs\n", input);
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
  return (egc_run(argc, argv, env, launch));
}
