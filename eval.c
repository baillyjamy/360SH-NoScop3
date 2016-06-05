/*
** eval.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Jun  3 23:55:56 2016 antoine
** Last update Sun Jun 05 18:42:54 2016 Antoine Baudrand
*/

#include <sys/wait.h>
#include <assert.h>
#include "eval.h"
#include "exec.h"

static int      wait_return_status(int pid)
{
  int		status;

  while (42)
    {
      if (waitpid(pid, &status, 0) == -1)
	  return (130);
      if (check_sigsegv(status) == -1)
	return (139);
      if (WIFEXITED(status))
	return (WEXITSTATUS(status));
    }
  return (0);
}

static int      eval_command_path(const t_node *node, t_hs command_path)
{
  t_process     *process;
  t_exec        e;

  e.filename = command_path;
  e.argv = glist_hs_copy(&node->args);
  e.env = scope_to_glist(&STATICS->env);
  e.stdin_fd = node->redir.input;
  e.stdout_fd = node->redir.output;
  e.stderr_fd = node->redir.error_output;
  process = exec(&e);
  return (wait_return_status(process->pid));
}

int		check_execution_path(t_hs cmd)
{
  if ((access(hs_to_str(cmd), F_OK)))
    {
      egc_fprintf(STDERR_FILENO, "%hs: Command not found.\n", cmd);
      return (1);
    }
  else if (is_dir(hs_to_str(cmd)) || access(hs_to_str(cmd), X_OK))
    {
      egc_fprintf(STDERR_FILENO, "%hs: Permission denied.\n", cmd);
      return (1);
    }
  return (0);
}

int              eval_command(const t_node *node)
{
  t_hs                  cmd;
  t_hs                  cmd_path;
  t_bltin_function      bltin;
  t_glist_hs            path_list;

  assert(glist_hs_length(&node->args));
  cmd = glist_hs_get(&node->args, 0);
  bltin = find_bltin(cmd);
  if (bltin)
    return (eval_bltin(node, bltin));
  path_list = get_path_list();
  cmd_path = find_executable(&path_list, cmd);
  if (hs_find(cmd, hs(".."), 0) != -1 || hs_find_char(cmd, '/', 0) != -1)
    if (check_execution_path(cmd))
	return (1);
      cmd_path = cmd;
  if (!hs_length(cmd_path))
    {
      egc_fprintf(STDERR_FILENO, "%hs: Command not found.\n", cmd);
      return (1);
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
      if (i)
        {
          if (last_status && child->prev_op == LIST_OP_AND_AND)
            return (last_status);
          if (!last_status && child->prev_op == LIST_OP_PIPE_PIPE)
            return (0);
        }
      last_status = eval(child);
    }
  return (last_status);
}

int     eval(const t_node *node)
{
  if (node->type == NODE_PIPE)
    return (eval_pipe(node));
  if (node->type == NODE_COMMAND)
    return (eval_command(node));
  if (node->type == NODE_LIST)
    return (eval_list(node));
  assert(0);
  return (0);
}
