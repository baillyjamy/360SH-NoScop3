/*
** exec.h for 42sh in /home/antoine/42sh
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Mon May 30 14:33:55 2016 Antoine Baudrand
** Last update Mon May 30 14:48:47 2016 Antoine Baudrand
*/

#ifndef EXEC_H_
# define EXEC_H_

typedef struct      s_exec
{
  const char        *filename;
  const char        **argv;
  const char        *envp;
  int               stdin_fd;
  int               stdout_fd;
  int               stderr_fd;
}                   t_exec;

typedef struct      s_process
{
  pid_t             pid;
  int               exit_code;
}                   t_process;

t_process           *exec(t_exec *);

#endif /* !EXEC_H_ */
