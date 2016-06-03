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

static int      eval_command(t_node *node)
{
  t_process     *process;
  t_exec        e;
  t_glist_hs    path_list;
  t_hs          cmd;

  assert(glist_hs_length(&node->args));
  cmd = glist_hs_get(&node->args, 0);
  path_list = get_path_list();
  e.filename = find_executable(&path_list, cmd);
  if (!hs_length(e.filename))
    {
      egc_fprintf(STDERR_FILENO, "%hs: Command not found.\n", cmd);
      return (-1);
    }
  e.argv = glist_hs_copy(&node->args);
  e.env = glist_hs_new();
  e.stdin_fd = node->redir.input;
  e.stdout_fd = node->redir.output;
  e.stderr_fd = node->redir.error_output;
  process = exec(&e);
  return (0);
}

int     eval(t_node *node)
{
  if (node->type == NODE_COMMAND)
    return (eval_command(node));
  assert(0);
  return (0);
}
