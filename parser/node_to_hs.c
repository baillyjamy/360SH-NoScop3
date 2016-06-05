/*
** node_to_hs.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Jun  4 22:11:39 2016 antoine
** Last update Sat Jun  4 22:11:39 2016 antoine
*/

#include <assert.h>
#include <unistd.h>
#include "private.h"

static t_hs     list_to_hs(const t_node *node, t_hs separator)
{
  int           i;
  t_hs          s;
  t_node        *child;

  s = hs("");
  i = -1;
  while (++i < glist_voidp_length(&node->children))
    {
      if (i)
        s = hs_concat(s, separator);
      child = glist_voidp_get(&node->children, i);
      s = hs_concat(s, node_to_hs(child));
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
  else if (node->type == NODE_PIPE)
    return (list_to_hs(node, hs(" | ")));
  else if (node->type == NODE_LIST)
    return (list_to_hs(node, hs("; ")));
  assert(0);
}
