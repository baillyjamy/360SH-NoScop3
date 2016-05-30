/*
** exec.h for 42sh in /home/antoine/42sh
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Mon May 30 14:33:55 2016 Antoine Baudrand
** Last update Mon May 30 15:27:47 2016 Antoine Baudrand
*/

#ifndef EXEC_H_
# define EXEC_H_

#include <unistd.h>

typedef struct      s_exec
{
  const char        *filename;
  const char        **argv;
  const char        *envp;
  const int         stdin_fd;
  const int         stdout_fd;
  const int         stderr_fd;
}                   t_exec;

typedef struct      s_process
{
  const pid_t       pid;
  int               exit_code;
}                   t_process;

t_process           *exec(const t_exec *);

#endif /* !EXEC_H_ */
