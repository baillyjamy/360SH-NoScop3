/*
** parser_list.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 15:21:45 2016 antoine
** Last update Sun Jun  5 15:21:45 2016 antoine
*/

#include "private.h"

static int      parse_list_op(t_token_list **list_pointer,
                              t_list_op *op,
                              t_hs *error)
{
  *error = hs("");
  *op = LIST_OP_SEMICOLON;
  if (parse_token_type_impl(list_pointer, TOKEN_TYPE_SEMICOLON))
    return (0);
  *op = LIST_OP_AND_AND;
  if (parse_token_type_impl(list_pointer, TOKEN_TYPE_AND_AND))
    return (0);
  *op = LIST_OP_PIPE_PIPE;
  if (parse_token_type_impl(list_pointer, TOKEN_TYPE_PIPE_PIPE))
    return (0);
  return (-1);
}

void    my_function_was_too_long_for_this_damn_norm(t_redir *redir,
                                                    t_list_op *op,
                                                    t_node **list)
{
  parser_redir_init(redir);
  *list = node_new(NODE_LIST, redir);
  (*list)->children = glist_voidp_new();
  *op = LIST_OP_SEMICOLON;
}

static t_parser_result  parse_list_item(t_token_list **list_pointer,
                                        t_list_op op,
                                        const t_node *list)
{
  t_parser_result       result;

  result = parse_pipeline(list_pointer);
  if (hs_length(result.error))
    return (result);
  if (!result.node)
    {
      if (glist_voidp_length(&list->children) && op != LIST_OP_SEMICOLON)
        return (ERROR(hs("Invalid null command.")));
      return (result);
    }
  result.node->prev_op = op;
  return (result);
}

t_parser_result         parse_command_list(t_token_list **list_pointer)
{
  t_node                *list;
  t_parser_result       result;
  t_redir               redir;
  t_list_op             op;
  t_hs                  error;

  my_function_was_too_long_for_this_damn_norm(&redir, &op, &list);
  while (1)
    {
      result = parse_list_item(list_pointer, op, list);
      if (hs_length(result.error))
        return (result);
      if (!result.node)
        break ;
      glist_voidp_append(&list->children, result.node);
      if (parse_list_op(list_pointer, &op, &error))
        {
          if (hs_length(error))
            return (ERROR(error));
          break ;
        }
    }
  return (NODE(list));
}
