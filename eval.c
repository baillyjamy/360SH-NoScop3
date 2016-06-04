/*
** eval.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Jun  3 23:55:56 2016 antoine
** Last update Sun Jun 05 01:08:55 2016 Antoine Baudrand
*/

#include <sys/wait.h>
#include <assert.h>
#include "eval.h"
#include "exec.h"

static int      eval_command_path(const t_node *node, t_hs command_path)
{
  t_process     *process;
  t_exec        e;
  int           status;

  e.filename = command_path;
  e.argv = glist_hs_copy(&node->args);
  e.env = STATICS->env;
  e.stdin_fd = node->redir.input;
  e.stdout_fd = node->redir.output;
  e.stderr_fd = node->redir.error_output;
  process = exec(&e);
  waitpid(process->pid, &status, 0);
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
  hs_puts(cmd);
  cmd_path = find_executable(&path_list, cmd);
  if (hs_find(cmd, hs(".."), 0) != -1 || hs_find_char(cmd, '/', 0) != -1)
    cmd_path = cmd;
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
