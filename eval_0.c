/*
** eval_0.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sun Jun  5 01:55:31 2016 Valentin Pichard
** Last update Sun Jun 05 12:12:41 2016 Antoine Baudrand
*/

#include <sys/wait.h>
#include <assert.h>
#include "eval.h"
#include "exec.h"
#include "sh.h"

int             eval_pipe(const t_node *node)
{
  t_node        *child;
  int           i;

  i = 0;
  while (i < glist_voidp_length(&node->children))
    {
      child = glist_voidp_get(&node->children, i);
      eval_command(child);
      i++;
    }
  return (0);
}

int		eval_paren(const t_node *node)
{
  assert(0);
  return (0);
}

int		eval_background(const t_node *node)
{
  assert(0);
  return (0);
}

int		eval_and(const t_node *node)
{
  assert(0);
  return (0);
}

int		eval_or(const t_node *node)
{
  assert(0);
  return (0);
}
