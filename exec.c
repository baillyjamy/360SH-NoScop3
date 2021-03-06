/*
** exec.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Wed Jun 01 00:18:15 2016 Antoine Baudrand
** Last update Sun Jun 05 21:38:58 2016 Antoine Baudrand
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "exec.h"
#include "egc.h"

/*
** Returns a NULL-terminated array of NUL-terminated C strings.
**
** Warning: The retuned array is allocated with the system `malloc()`,
** and should be freed.
*/
static char     **hs_list_to_charpp(const t_glist_hs *list)
{
  int           i;
  char          **array;

  array = malloc(sizeof(char *) * (glist_hs_length(list) + 1));
  i = -1;
  while (++i < glist_hs_length(list))
    {
      array[i] = strdup(hs_to_str(glist_hs_get(list, i)));
    }
  array[i] = NULL;
  return (array);
}

static void     free_char_array(char **array)
{
  char          **begin;

  begin = array;
  while (*array)
    {
      free(*array);
      array++;
    }
  free(begin);
}

static int      execve_wrapper(const t_exec *exec)
{
  char          *file;
  char          **argv;
  char          **env;
  int           r;

  file = strdup(hs_to_str(exec->filename));
  argv = hs_list_to_charpp(&exec->argv);
  env = hs_list_to_charpp(&exec->env);
  r = execve(file, argv, env);
  free_char_array(argv);
  free_char_array(env);
  free(file);
  egc_fprintf(STDERR_FILENO, "Unable to execve %hs\n", exec->filename);
  egc_exit(127);
  return (r);
}

t_process       *exec(const t_exec *exec)
{
  t_process     *proc;
  int           dup_res;

  proc = EGC_NEW(t_process);
  proc->exit_code = 0;
  if ((proc->pid = fork()) == 0)
    {
      if (!(dup_res = 0) && exec->stdin_fd != STDIN_FILENO)
        dup_res = dup2(exec->stdin_fd, STDIN_FILENO);
      if (exec->stdout_fd != STDOUT_FILENO)
        dup_res = dup2(exec->stdout_fd, STDOUT_FILENO);
      if (exec->stderr_fd != STDERR_FILENO)
        dup_res = dup2(exec->stderr_fd, STDERR_FILENO);
      if (dup_res < 0)
        egc_exit(127);
      execve_wrapper(exec);
    }
  if (exec->stdin_fd != STDIN_FILENO)
    close(exec->stdin_fd);
  if (exec->stdout_fd != STDOUT_FILENO)
    close(exec->stdout_fd);
  if (exec->stderr_fd != STDERR_FILENO)
    close(exec->stdin_fd);
  return (proc);
}
