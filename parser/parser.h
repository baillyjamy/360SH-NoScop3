/*
** parser.h for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Jun  2 23:04:47 2016 antoine
** Last update Fri Jun 03 12:35:33 2016 Antoine Baudrand
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "../lexer/lexer.h"
# include "../sh.h"

typedef enum    e_node_type
{
  NODE_PIPE,
  NODE_COMMAND,
  NODE_PAREN,
  NODE_LIST,
}               t_node_type;

typedef enum    e_list_op
{
  LIST_OP_AND_AND,
  LIST_OP_PIPE_PIPE,
  LIST_OP_SEMICOLON,
}               t_list_op;

char const      *node_type_to_str(t_node_type type);

typedef struct  s_redir
{
  int           input;
  int           output;
  int           error_output;
}               t_redir;

struct                  s_node;
typedef struct s_node   t_node;

/*
** `type` is the type of the node. The followings types define
** the following properties:
**
** NODE_PIPE:
**      children: The children nodes (separated by "|")
**
** NODE_COMMAND:
**      args: The command name and its arguments
**
** NODE_PAREN:
**      left: The child node, between the parens
**
** NODE_LIST:
**      children: The children nodes (separated by semicolons)
**
** <all node types>:
**      type: The type of the node.
**      redir: The redirections file descriptors.
**      If one of these file descriptors is not equal to 0, 1 or 2, it is
**      open and should be closed.
**
** The other properties are left undefined.
*/
struct  s_node
{
  t_node_type   type;
  t_list_op     prev_op;
  t_redir       redir;
  t_glist_hs    args;
  t_glist_voidp children;
};

void    parser_redir_close(t_redir *redir);

/*
** Close the file descriptors associated with the given node.
*/
void    node_close(t_node *node);

/*
** Returns a string describing the node, for debugging purposes.
*/
t_hs    node_to_hs(const t_node *node);

/*
** If `success` is true, `error` is unititialized.
** If `success` is false, `error` contains an error message.
*/
typedef struct  s_parser_result
{
  t_node        *node;
  t_hs          error;
  int           success;
}               t_parser_result;

t_parser_result parse(t_token_list *tokens);

#endif /* !PARSER_H_ */
