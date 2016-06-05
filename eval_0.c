/*
** eval_0.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sun Jun  5 01:55:31 2016 Valentin Pichard
** Last update Sun Jun  5 02:11:14 2016 Valentin Pichard
*/

#include <sys/wait.h>
#include <assert.h>
#include "eval.h"
#include "exec.h"

int		eval_pipe(const t_node *node)
{
  egc_printf("eval this pipe: %hs\n", node_to_hs(node));
  assert(0);
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
