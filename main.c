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

static int              eval_tokens(t_token_list *tokens)
{
  t_parser_result       parse_res;
  int                   r;

  parse_res = parse(tokens);
  if (!parse_res.success)
    {
      hs_puts(parse_res.error);
      return (1);
    }
  /*
  hs_puts(node_to_hs(parse_res.node));
  hs_puts(hs("------------------------"));
  */
  r = eval(parse_res.node);
  /*
  egc_printf("status %d\n", r);
  */
  return (r < 0 ? 1 : r);
}

static void     exit_on_ctrl_d(int r)
{
  t_glist_hs    args;

  args = hs_split(hs_format("exit %d", r), hs(" "));
  STATICS->in = STDIN_FILENO;
  STATICS->out = STDOUT_FILENO;
  STATICS->err = STDERR_FILENO;
  exit_cmd(&args);
}

static t_token_list     *read_and_lex(t_readline *readline, int last_status)
{
  t_lexer_result        lex_res;
  t_hs                  input;
  t_hs                  c;

  readline_set_prompt(readline, create_prompt());
  if (readline_read(readline, &input))
    exit_on_ctrl_d(last_status);
  while (1)
    {
      lex_res = lex(input);
      if (!lex_res.error)
        break ;
      if (!hs_equals(hs("Expected here document end delimiter"),
                     lex_res.error->message))
        {
          hs_puts(syntax_error_to_hs(lex_res.error));
          return (read_and_lex(readline, last_status));
        }
      input = hs_format("%hs\n", input);
      readline_set_prompt(readline, hs("? "));
      if (readline_read(readline, &c))
        return (read_and_lex(readline, last_status));
      input = hs_format("%hs%hs\n", input, c);
    }
  return (lex_res.tokens);
}

static int      read_and_eval(t_readline *readline, int last_status)
{
  t_token_list  *tokens;

  tokens = read_and_lex(readline, last_status);
  if (!tokens)
    return (read_and_eval(readline, last_status));
  return (eval_tokens(tokens));
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
  t_readline    *readline;
  t_statics     statics;
  int           r;

  (void) argc;
  (void) argv;
  signal(SIGINT, ctrl_c);
  statics_init(&statics);
  egc_set_statics(&statics, sizeof(t_statics));
  scope_init_from_str_array(&statics.env, env);
  readline = readline_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
  update_shell_level();
  r = 0;
  while (42)
    r = read_and_eval(readline, r);
  return (r);
}

int             main(int argc, char **argv, char **env)
{
  return (egc_run(argc, argv, env, main_loop));
}
