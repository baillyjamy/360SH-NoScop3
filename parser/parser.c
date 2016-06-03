/*
** parser.c for parser in /home/antoine/360SH-NoScop3/parser
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Fri Jun 03 11:18:33 2016 Antoine Baudrand
** Last update Fri Jun 03 12:03:16 2016 Antoine Baudrand
*/

#include "../lexer/lexer.h"
#include "parser.h"

void        parse(t_token_list *tokens)
{
  t_node    *nodes;

  nodes = NULL;
  add_node(NODE_PIPE, nodes);
  while (tokens)
    {
      egc_printf("----| TOKEN |----\n type: %s\n string: %hs\n value: %hs\n",
                 token_type_to_str(tokens->token->type),
                 tokens->token->string_value,
                 tokens->token->source);
      tokens = tokens->next;
    }
}
