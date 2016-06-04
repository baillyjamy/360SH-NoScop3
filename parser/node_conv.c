/*
** node_conv.c for parser in /home/antoine/360SH-NoScop3/parser
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Sat Jun 04 19:13:19 2016 Antoine Baudrand
** Last update Sat Jun 04 19:13:44 2016 Antoine Baudrand
*/

#include <assert.h>
#include <unistd.h>
#include "private.h"

static t_hs     list_to_hs(const t_node *node)
{
  int           i;
  t_hs          s;
  t_node        *child;

  s = hs("");
  i = -1;
  while (++i < glist_voidp_length(&node->children))
    {
      child = glist_voidp_get(&node->children, i);
      s = hs_concat(s, node_to_hs(child));
      s = hs_concat(s, hs("; "));
    }
  return (s);
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
    return (hs_join(hs(" "), &node->args));
  else if (node->type == NODE_LIST)
    return (list_to_hs(node));
  assert(0);
}
