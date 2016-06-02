/*
** exec.c for 42sh in /home/antoine/42sh
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Wed Jun 01 00:18:15 2016 Antoine Baudrand
** Last update Thu Jun  2 22:51:17 2016 Valentin Pichard
*/

#include <unistd.h>
#include <stdlib.h>
#include "exec.h"
#include "egc.h"

t_glist_hs	get_path(void)
{
  t_hs		value;
  t_glist_hs	path;

  path = glist_hs_new();
  if (env_get_variable(hs("PATH"), &value) == -1)
    return (path);
  path = hs_split(value, hs(":"));
  return (path);
}

/*
** Returns a NULL-terminated array of NUL-terminated C strings.
*/
static char     **hs_list_to_charpp(const t_glist_hs *list)
{
  int           i;
  char          **array;

  array = egc_malloc(sizeof(char *) + 1);
  i = -1;
  while (++i < glist_hs_length(list))
    {
      array[i] = hs_to_str(glist_hs_get(list, i));
    }
  array[i] = NULL;
  return (array);
}

static int      execve_wrapper(const t_exec *exec)
{
  char          *file;
  char          **argv;
  char          **env;

  file = hs_to_str(exec->filename);
  argv = hs_list_to_charpp(&exec->argv);
  env = hs_list_to_charpp(&exec->env);
  return (execve(file, argv, env));
}

t_process       *exec(const t_exec *exec)
{
  t_process     *proc;

  proc = EGC_NEW(t_process);
  proc->exit_code = 0;
  proc->pid = fork();
  if (proc->pid == 0)
    {
      if (exec->stdout_fd != STDOUT_FILENO)
        dup2(exec->stdout_fd, STDOUT_FILENO);
      if (exec->stdin_fd != STDIN_FILENO)
        dup2(exec->stdin_fd, STDIN_FILENO);
      if (exec->stderr_fd != STDERR_FILENO)
        dup2(exec->stdin_fd, STDERR_FILENO);
      execve_wrapper(exec);
      egc_fprintf(STDERR_FILENO, "Unable to execve %hs\n", exec->filename);
      egc_exit(127);
    }
  if (exec->stdout_fd != STDOUT_FILENO)
    close(exec->stdout_fd);
  if (exec->stdin_fd != STDIN_FILENO)
    close(exec->stdin_fd);
  if (exec->stderr_fd != STDERR_FILENO)
    close(exec->stdin_fd);
  return (proc);
}
