/*
** exec.h for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Mon May 30 14:33:55 2016 Antoine Baudrand
** Last update Fri Jun 03 16:25:12 2016 Antoine Baudrand
*/

#ifndef EXEC_H_
# define EXEC_H_

# include <unistd.h>
# include <sys/types.h>

# include "sh.h"

/*
** yan typedef pid_t
*/
typedef struct  s_exec
{
  t_hs          filename;
  t_glist_hs    argv;
  t_glist_hs    env;
  int           stdin_fd;
  int           stdout_fd;
  int           stderr_fd;
}               t_exec;

typedef struct  s_process
{
  pid_t         pid;
  int           exit_code;
}               t_process;

t_process       *exec(const t_exec *);
t_glist_hs	get_path(void);

#endif /* !EXEC_H_ */
