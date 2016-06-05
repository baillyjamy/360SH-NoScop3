/*
** eval_check.c for  in /home/bailly_j/rendu/360SH-NoScop3/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Jun  5 21:44:36 2016 Jamy Bailly
** Last update Sun Jun  5 21:44:36 2016 Jamy Bailly
*/

#include <sys/wait.h>
#include "eval.h"

int      wait_return_status(int pid)
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

int		eval_check_execution_path(t_hs cmd)
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
