/*
** main.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon May 30 19:08:52 2016 Pierre-Emmanuel Jacquier
** Last update Fri Jun 03 11:26:08 2016 Antoine Baudrand
*/

#include "sh.h"
#include "readline/readline.h"
#include "lexer/lexer.h"
#include "parser/parser.h"

int		    launch(int argc, char **argv, char **env)
{
  t_hs		    input;
  t_readline	    *readline;
  t_statics         statics;
  t_token_list      *tokens;

  (void) argc;
  (void) argv;
  statics_init(&statics);
  egc_set_statics(&statics, sizeof(t_statics));
  env_init(env);
  while (42)
    {
      readline = readline_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
      readline_set_prompt(readline, create_prompt());
      input = readline_read(readline);
      if (hs_get(input, 0) != '\0')
	{
          tokens = lex(input).tokens;
          parse(tokens);
	}
    }
  return (0);
}

int             main(int argc, char **argv, char **env)
{
  return (egc_run(argc, argv, env, launch));
}
