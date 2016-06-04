/*
** eval.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Jun  3 23:55:56 2016 antoine
** Last update Fri Jun  3 23:55:56 2016 antoine
*/

#include <assert.h>
#include "eval.h"
#include "exec.h"

static void     get_bltins(t_bltin *bltins)
{
  int           i;

  i = 0;
  bltins[i].name = "env";
  bltins[i++].function = env_cmd;
  bltins[i].name = "setenv";
  bltins[i++].function = setenv_cmd;
  bltins[i].name = "cd";
  bltins[i++].function = cd_cmd;
  bltins[i].name = "exit";
  bltins[i++].function = exit_cmd;
  bltins[i].name = "unsetenv";
  bltins[i++].function = unsetenv_cmd;
  bltins[i].name = "echo";
  bltins[i++].function = echo_cmd;
  bltins[i].name = NULL;
  bltins[i++].function = NULL;
}

static t_bltin_function find_bltin(t_hs command)
{
  t_bltin               builtins[32];
  t_bltin               *builtin;

  get_bltins(builtins);
  builtin = builtins;
  while (builtin->name)
    {
      if (hs_equals(command, hs(builtin->name)))
        return (builtin->function);
      builtin++;
    }
  return (NULL);
}

static int      eval_command_path(const t_node *node, t_hs command_path)
{
  t_process     *process;
  t_exec        e;

  e.filename = command_path;
  e.argv = glist_hs_copy(&node->args);
  e.env = glist_hs_new();
  e.stdin_fd = node->redir.input;
  e.stdout_fd = node->redir.output;
  e.stderr_fd = node->redir.error_output;
  process = exec(&e);
  return (0);
}

static int              eval_command(const t_node *node)
{
  t_hs                  cmd;
  t_hs                  cmd_path;
  t_bltin_function      bltin;
  t_glist_hs            path_list;
  t_glist_hs            new_args;

  assert(glist_hs_length(&node->args));
  cmd = glist_hs_get(&node->args, 0);
  bltin = find_bltin(cmd);
  if (bltin)
    {
      new_args = glist_hs_copy(&node->args);
      return (bltin(&new_args));
    }
  path_list = get_path_list();
  cmd_path = find_executable(&path_list, cmd);
  if (!hs_length(cmd_path))
    {
      egc_fprintf(STDERR_FILENO, "%hs: Command not found.\n", cmd);
      return (-1);
    }
  return (eval_command_path(node, cmd_path));
}

static int      eval_list(const t_node *node)
{
  int           i;
  int           last_status;
  t_node        *child;

  i = -1;
  last_status = 0;
  while (++i < glist_voidp_length(&node->children))
    {
      child = glist_voidp_get(&node->children, i);
      last_status = eval(child);
    }
  return (last_status);
}

int     eval(const t_node *node)
{
  if (node->type == NODE_COMMAND)
    return (eval_command(node));
  if (node->type == NODE_LIST)
    return (eval_list(node));
  assert(0);
  return (0);
}
