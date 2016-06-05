/*
** parser_0.c for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Sat Jun 04 19:33:44 2016 Antoine Baudrand
** Last update Sat Jun 04 19:57:09 2016 Antoine Baudrand
*/

#include <assert.h>
#include "private.h"

t_parser_result parse_command_end(t_token_list **list_pointer,
                                  t_node *node)
{
  t_hs          word;

  while (1)
    {
      if (parse_word_or_string(list_pointer, &word, &node->redir))
        return (ERROR(word));
      if (!hs_length(word))
        break ;
      glist_hs_append(&node->args, word);
    }
  return (NODE(node));
}

t_parser_result parse_command(t_token_list **list_pointer)
{
  t_node        *node;
  t_hs          word;
  t_redir       redir;

  parser_redir_init(&redir);
  if (parse_word_or_string(list_pointer, &word, &redir))
    return (ERROR(word));
  if (!hs_length(word))
    return (NULL_RESULT);
  node = node_new(NODE_COMMAND, &redir);
  node->args = glist_hs_new();
  glist_hs_append(&node->args, word);
  return (parse_command_end(list_pointer, node));
}

t_parser_result         parse(t_token_list *tokens)
{
  t_parser_result       result;

  result = parse_command_list(&tokens);
  if (!result.success)
    return (result);
  if (tokens)
    {
      return (ERROR(hs_format("Unexpected token '%hs'.",
                              tokens->token->source)));
    }
  assert(result.node);
  return (result);
}
