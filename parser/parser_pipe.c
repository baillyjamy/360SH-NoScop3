/*
** parser_pipe.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 15:02:10 2016 antoine
** Last update Sun Jun  5 15:02:10 2016 antoine
*/

#include "private.h"

static t_parser_result  parse_pipeline_end(t_node *first,
                                           t_token_list **list_pointer,
                                           t_redir *redir)
{
  t_node                *list;
  t_parser_result       result;
  t_token_result        tr;

  list = node_new(NODE_PIPE, redir);
  list->children = glist_voidp_new();
  glist_voidp_append(&list->children, first);
  while (*list_pointer)
    {
      tr = parse_token_type(list_pointer, TOKEN_TYPE_PIPE, redir);
      if (TOKEN_RESULT_IS_NULL(tr))
        break ;
      if (TOKEN_RESULT_IS_ERR(tr))
        return (ERROR(tr.error));
      result = parse_command(list_pointer);
      if (hs_length(result.error))
        return (result);
      if (!result.node)
        break ;
      glist_voidp_append(&list->children, result.node);
    }
  list->redir = *redir;
  return (NODE(list));
}

static t_hs     parser_setup_pipeline(t_node *node)
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
          if (pipe(pipefd))
            return (hs("pipe() error"));
          child->redir.output = pipefd[1];
        }
      i++;
    }
  return (hs(""));
}

t_parser_result         parse_pipeline(t_token_list **list_pointer)
{
  t_parser_result       result;
  t_redir               redir;
  t_node                *first;
  t_hs                  error;

  parser_redir_init(&redir);
  result = parse_command(list_pointer);
  first = result.node;
  if (!first)
    return (result);
  result = parse_pipeline_end(first, list_pointer, &redir);
  if (!result.node)
    return (result);
  if (glist_voidp_length(&result.node->children) == 1)
    return (NODE(first));
  if (hs_length(error = parser_setup_pipeline(result.node)))
    return (ERROR(error));
  return (result);
}
