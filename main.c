/*
** main.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon May 30 19:08:52 2016 Pierre-Emmanuel Jacquier
** Last update Fri Jun 03 11:26:08 2016 Antoine Baudrand
*/

#include <unistd.h>
#include "readline/readline.h"
#include "eval.h"

static void             eval_hs(t_hs input)
{
  t_lexer_result        lex_res;
  t_parser_result       parse_res;

  lex_res = lex(input);
  if (lex_res.error)
    {
      hs_puts(syntax_error_to_hs(lex_res.error));
      return ;
    }
  hs_puts(token_list_to_hs(lex_res.tokens));
  parse_res = parse(lex_res.tokens);
  if (!parse_res.success)
    {
      hs_puts(parse_res.error);
      return ;
    }
  hs_puts(node_to_hs(parse_res.node));
  hs_puts(hs("------------------------"));
  eval(parse_res.node);
}

static void     exit_on_ctrl_d(void)
{
  t_glist_hs    args;

  args = hs_split(hs("exit"), hs(""));
  exit_cmd(&args);
}

static int      main_loop(int argc, char **argv, char **env)
{
  t_hs          input;
  t_readline    *readline;
  t_statics     statics;

  (void) argc;
  (void) argv;
  statics_init(&statics);
  egc_set_statics(&statics, sizeof(t_statics));
  env_init(env);
  readline = readline_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
  readline_set_prompt(readline, create_prompt());
  while (42)
    {
      if (readline_read(readline, &input))
        exit_on_ctrl_d();
      if (hs_length(input))
        eval_hs(input);
    }
  return (0);
}

int             main(int argc, char **argv, char **env)
{
  return (egc_run(argc, argv, env, main_loop));
}
