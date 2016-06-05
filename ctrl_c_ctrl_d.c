/*
** ctrl_c_ctrl_d.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 21:09:14 2016 antoine
** Last update Sun Jun  5 21:09:14 2016 antoine
*/

#include "sh.h"

void            exit_on_ctrl_d(int r)
{
  t_glist_hs    args;

  args = hs_split(hs_format("exit %d", r), hs(" "));
  STATICS->in = STDIN_FILENO;
  STATICS->out = STDOUT_FILENO;
  STATICS->err = STDERR_FILENO;
  exit_cmd(&args);
}

/*
** TODO: We can't use any garbage-collected stuff in an signal handler.
** We should do this differently.
*/
void	ctrl_c()
{
  return ;
}
