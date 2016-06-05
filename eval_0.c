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

int		eval_pipe(t_node    *node)
{
  int           i;
  t_node        *child;
  int           pipefd[2];

  i = 0;
  while (i < glist_voidp_length(&node->children))
    {
      child = glist_voidp_get(&node->children, i);
      if (i)
        child->redir.input = pipefd[0];
      if ((i + 1) < glist_voidp_length(&node->children))
        {
          pipe(pipefd);
          child->redir.output = pipefd[1];
        }
      i += 1;
    }
  i = 0;
  while (i < glist_voidp_length(&node->children))
    {
      child = glist_voidp_get(&node->children, i);
      eval_command(child);
      i += 1;
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
