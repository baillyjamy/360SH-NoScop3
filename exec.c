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
#include <string.h>
#include <errno.h>
#include "exec.h"
#include "egc.h"

t_glist_hs	get_path_list(void)
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
  return (r);
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

t_hs    concat_path(t_hs left, t_hs right)
{
  char  left_char;

  if (!hs_length(left))
    return (right);
  if (!hs_length(right))
    return (left);
  left_char = hs_get(left, hs_length(left) - 1);
  if (left_char == '/' || hs_get(right, 0) == '/')
    return (hs_concat(left, right));
  return (hs_format("%hs/%hs", left, right));
}

t_hs    find_executable(t_glist_hs *path_list, t_hs cmd_name)
{
  int   i;
  t_hs  path;

  if (!hs_length(cmd_name) || hs_get(cmd_name, 0) == '/')
    return (cmd_name);
  i = -1;
  while (++i < (int)glist_hs_length(path_list))
    {
      path = concat_path(glist_hs_get(path_list, i), cmd_name);
      if (file_exist(path))
        return (path);
    }
  return (hs(""));
}
