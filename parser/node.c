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
#include "private.h"

t_node          *node_new(t_node_type type, const t_redir *redir)
{
  t_node        *new;

  new = EGC_NEW(t_node);
  new->type = type;
  new->redir = *redir;
  return (new);
}

void    parser_redir_init(t_redir *redir)
{
  redir->input = STDIN_FILENO;
  redir->output = STDOUT_FILENO;
  redir->error_output = STDERR_FILENO;
}

void    parser_redir_close(t_redir *redir)
{
  assert(redir->input >= 0);
  assert(redir->output >= 0);
  assert(redir->error_output >= 0);
  if (redir->input > 2)
    close(redir->input);
  if (redir->output > 2)
    close(redir->output);
  if (redir->error_output > 2)
    close(redir->error_output);
  redir->input = -1;
  redir->output = -1;
  redir->error_output = -1;
}

void    node_close(t_node *node)
{
  parser_redir_close(&node->redir);
}

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
