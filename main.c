/*
** main.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon May 30 19:08:52 2016 Pierre-Emmanuel Jacquier
** Last update Sat Jun 04 18:40:09 2016 Antoine Baudrand
*/

#include <unistd.h>
#include <signal.h>
#include "readline/readline.h"
#include "sh.h"
#include "eval.h"

static int              eval_hs(t_hs input)
{
  t_lexer_result        lex_res;
  t_parser_result       parse_res;
  int                   r;

  lex_res = lex(input);
  if (lex_res.error)
    {
      hs_puts(syntax_error_to_hs(lex_res.error));
      return (1);
    }
  parse_res = parse(lex_res.tokens);
  if (!parse_res.success)
    {
      hs_puts(parse_res.error);
      return (1);
    }
  /*hs_puts(node_to_hs(parse_res.node));
  hs_puts(hs("------------------------"));*/
  r = eval(parse_res.node);
  return (r < 0 ? 1 : r);
}

static void     exit_on_ctrl_d(int r)
{
  t_glist_hs    args;

  args = hs_split(hs_format("exit %d", r), hs(" "));
  exit_cmd(&args);
}

/*
** TODO: We can't use any garbage-collected stuff in an signal handler.
** We should do this differently.
*/
void	ctrl_c()
{
}

static int      main_loop(int argc, char **argv, char **env)
{
  t_hs          input;
  t_readline    *readline;
  t_statics     statics;
  int           r;

  (void) argc;
  (void) argv;
  signal(SIGINT, ctrl_c);
  statics_init(&statics);
  egc_set_statics(&statics, sizeof(t_statics));
  env_init(env);
  readline = readline_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
  update_shell_level();
  while (42)
    {
      if (!env_variable_exists(hs("PATH")))
	generate_path();
      readline_set_prompt(readline, create_prompt());
      if (readline_read(readline, &input))
        exit_on_ctrl_d(r);
      if (hs_length(input))
        r = eval_hs(input);
    }
  return (r);
}

int             main(int argc, char **argv, char **env)
{
  return (egc_run(argc, argv, env, main_loop));
}
