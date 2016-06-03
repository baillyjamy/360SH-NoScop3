/*
** parser.c for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Fri Jun 03 11:18:33 2016 Antoine Baudrand
** Last update Fri Jun 03 17:03:36 2016 Antoine Baudrand
*/

/*
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
*/

#include "private.h"

/*
** Try to read a token.
**
** Return a token or NULL.
*/
t_token         *parse_token_type(t_token_list **list_pointer,
                                  t_token_type type)
{
  t_token       *token;

  if (!*list_pointer)
    return (NULL);
  token = (*list_pointer)->token;
  if (type != token->type)
    return (NULL);
  *list_pointer = (*list_pointer)->next;
  return (token);
}

t_token         *parse_word_or_string_token(t_token_list **list_pointer)
{
  t_token       *token;

  token = parse_token_type(list_pointer, TOKEN_TYPE_WORD);
  if (token)
    return (token);
  token = parse_token_type(list_pointer, TOKEN_TYPE_D_QUOTES);
  if (token)
    return (token);
  token = parse_token_type(list_pointer, TOKEN_TYPE_S_QUOTES);
  if (token)
    return (token);
  return (NULL);
}

int             parse_word_or_string(t_token_list **list_pointer,
                                     t_hs *result)
{
  t_token       *token;

  token = parse_word_or_string_token(list_pointer);
  if (!token)
    return (-1);
  if (token->type == TOKEN_TYPE_WORD)
    *result = token->source;
  else
    *result = token->string_value;
  return (0);
}

t_parser_result parse_command(t_token_list **list_pointer)
{
  t_node        *node;
  t_hs          word;

  if (!*list_pointer)
    return (NULL_RESULT);
  if (parse_word_or_string(list_pointer, &word))
    return (NULL_RESULT);
  node = node_new(NODE_COMMAND);
  node->args = glist_hs_new();
  glist_hs_append(&node->args, word);
  return (NODE(node));
}

t_node          *node_new_empty_list(void)
{
  t_node        *node;

  node = node_new(NODE_LIST);
  node->children = glist_voidp_new();
  return (node);
}

t_parser_result         parse(t_token_list *tokens)
{
  t_parser_result       result;
  t_node                *node;

  result = parse_command(&tokens);
  if (result.success && !result.node)
    {
      node = node_new_empty_list();
      return (NODE(node));
    }
  return (result);
}

/*
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
*/
