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

char	**envp;

static char     read_char(void)
{
  char          c;

  if (read(STDIN_FILENO, &c, 1) != 1)
    return ('\0');
  return (c);
}

/*
** Reads a line from the standard input
**
** The line is terminated by a Ctrl+D or a '\n'.
*/

static t_hs     read_line(void)
{
  t_hs          line;
  char          c;

  line = hs_new_empty();
  while (1)
    {
      c = read_char();
      if (!c || c == '\n')
        break ;
      line = hs_concat_hs_char(line, c);
    }
  return (line);
}

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
  t_statics     statics;
  t_glist_hs	args;

  statics_init(&statics);
  egc_set_statics(&statics, sizeof(t_statics));
  env_init(envp);
  while (42)
    {
      env_get_variable(hs("USER"), &user);
      display_prompt(user, hs("42sh"));
      input = read_line();
      args = hs_split(input, hs(" "));
      bltin(&args);
    }
  return (0);
}

int             main(int argc, char **argv, char **env)
{
  envp = env;
  return (egc_run(0, NULL, main2));
}
