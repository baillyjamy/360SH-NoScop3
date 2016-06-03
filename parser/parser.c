/*
** parser.c for parser in /home/antoine/360SH-NoScop3/parser
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Fri Jun 03 11:18:33 2016 Antoine Baudrand
** Last update Fri Jun 03 14:47:46 2016 Antoine Baudrand
*/

#include "../lexer/lexer.h"
#include "../exec.h"
#include "parser.h"

static void     parse_command(t_token_list **tokens, t_node **nodes)
{
  *nodes = add_node(NODE_COMMAND, *nodes);
  while (*tokens &&
         ((*tokens)->token->type == TOKEN_TYPE_WORD
          || (*tokens)->token->type == TOKEN_TYPE_GT))
    {
      glist_hs_append(&(*nodes)->command.argv, (*tokens)->token->source);
      *tokens = (*tokens)->next;
    }
}


t_hs	        get_command_from_path(t_hs cmd)
{
  t_hs          res;
  t_glist_hs    path;
  int           i;
  int           len;

  path = get_path();
  glist_hs_length(&path);
  while (i < len)
    {
      res = my_strcat(*path, cmd->argv[0]);
      if ((!access(res, X_OK)) && (!is_dir(res)))
	{
	  cmd->cmd = res;
	  return (1);
	}
      free(res);
      path++;
    }
  return (0);
}

void        parse(t_token_list *tokens)
{
  t_node    *nodes;

  nodes = NULL;
  while (tokens)
    {
      if (tokens->token->type == TOKEN_TYPE_WORD || tokens->token->type == TOKEN_TYPE_GT)
        parse_command(&tokens, &nodes);
    }
  nodes->command.filename = glist_hs_get(&nodes->command.argv, 0);
  exec(&nodes->command);
}
