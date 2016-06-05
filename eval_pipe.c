/*
** eval_pipe.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 16:59:58 2016 antoine
** Last update Sun Jun  5 16:59:58 2016 antoine
*/

#include <sys/wait.h>
#include <assert.h>
#include "eval.h"
#include "exec.h"
#include "sh.h"

int             eval_pipe(t_node *node)
{
  t_node        *child;
  int           i;
  int           r;

  i = 0;
  while (i < glist_voidp_length(&node->children))
    {
      child = glist_voidp_get(&node->children, i);
      r = eval_command(child);
      if (r)
        return (r);
      i++;
    }
  return (0);
}
