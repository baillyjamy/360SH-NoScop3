/*
** exec.c for 42sh in /home/antoine/42sh
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Wed Jun 01 00:18:15 2016 Antoine Baudrand
** Last update Wed Jun 01 01:34:45 2016 Antoine Baudrand
*/

#include <unistd.h>
#include <stdlib.h>
#include "exec.h"
#include "egc.h"

t_process       *exec(const t_exec *exec)
{
  t_process     *proc;

  proc = egc_malloc(sizeof(t_process));
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
      execve(exec->filename, exec->argv, exec->envp);
      egc_fprintf(STDERR_FILENO, "Unable to execve %s\n", exec->filename);
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
