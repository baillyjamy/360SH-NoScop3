/*
** parser.c for parser in /home/antoine/360SH-NoScop3/parser
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Fri Jun 03 11:18:33 2016 Antoine Baudrand
** Last update Fri Jun 03 17:03:36 2016 Antoine Baudrand
*/

#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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

static int		is_dir(char *file_name)
{
  struct stat	file_stat;

  if (stat(file_name, &file_stat) != 0)
    return (0);
  else if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
    return (1);
  return (0);
}

t_hs	        get_command_from_path(t_hs cmd)
{
  t_hs          res;
  t_glist_hs    path;
  int           i;
  int           len;

  cmd = hs_concat_char_hs('/', cmd);
  path = get_path();
  len = glist_hs_length(&path);
  i = 0;
  while (i < len)
    {
      res = hs_concat(glist_hs_get(&path, i), cmd);
      if ((!access(hs_to_str(res), X_OK)) && !is_dir(hs_to_str(res)))
        return (res);
      i += 1;
    }
  return (hs_new_empty());
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
  nodes->command.filename = get_command_from_path(glist_hs_get(&nodes->command.argv, 0));
  exec(&nodes->command);
}
