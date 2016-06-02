/*
** test_exec.c for unit in /home/antoine/42sh/test/unit
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Wed Jun 01 01:20:33 2016 Antoine Baudrand
** Last update Wed Jun 01 01:45:10 2016 Antoine Baudrand
*/

#include "test.h"
#include "../../exec.h"
#include "../../egc.h"

void            test_suite_exec(void)
{
  t_exec        *e;
  t_process     *proc;

  e = EGC_NEW(t_exec);
  e->filename = hs("/bin/true");
  e->argv = hs_split(hs("true"), hs(""));
  e->env = hs_split(hs(""), hs(""));
  e->stdin_fd = 0;
  e->stdout_fd = 1;
  e->stderr_fd = 2;
  proc = exec(e);
  ASSERT(proc->pid > 0);
}
