/*
** node.c for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Fri Jun 03 11:50:59 2016 Antoine Baudrand
** Last update Fri Jun 03 14:07:47 2016 Antoine Baudrand
*/

#include <assert.h>
#include <unistd.h>
#include "parser.h"

t_node          *node_new(t_node_type type)
{
  t_node        *new;

  new = EGC_NEW(t_node);
  new->type = type;
  new->input = STDIN_FILENO;
  new->output = STDOUT_FILENO;
  new->error_output = STDERR_FILENO;
  return (new);
}

t_hs    node_to_hs(const t_node *node)
{
  if (node->type == NODE_BACKGROUND)
    {
      if (node->right)
        return (hs_format("%hs & %hs",
                          node_to_hs(node->left),
                          node_to_hs(node->right)));
      return (hs_format("%hs &", node_to_hs(node->left)));
    }
  else if (node->type == NODE_COMMAND)
    {
      return (hs_join(hs(" "), &node->args));
    }
  assert(0);
}
