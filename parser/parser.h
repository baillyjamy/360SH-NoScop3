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
  NODE_AND,
  NODE_OR,
  NODE_BACKGROUND,
  NODE_LIST,
}               t_node_type;

char const      *node_type_to_str(t_node_type type);

struct                  s_node;
typedef struct s_node   t_node;

/*
** `type` is the type of the node. The followings types define
** the following properties:
**
** NODE_PIPE:
**      left: The node at the left of the pipeline
**      right: The node at the right of the pipeline
**      pipe_background: True if `|&` was used, false if `|` was used.
**
** NODE_COMMAND:
**      args: The command name and its arguments
**
** NODE_PAREN:
**      left: The child node, between the parens
**
** NODE_BACKGROUND:
**      left: The node before the '&'
**      right: The node after the '&' or NULL
**
** NODE_AND:
**      left: The node at the left of `&&`
**      right: The node at the right of of `&&`
**
** NODE_OR:
**      left: The node at the left of `||`
**      right: The node at the right of of `||`
**
** NODE_LIST:
**      children: The children nodes (separated by semicolons)
**
** <all node types>:
**      type: The type of the node.
**      input, error_output, output: File descriptors. If one of these
**      file descriptors is not equal to 0, 1 or 2, it is open and should
**      be closed.
**
** The other properties are left undefined.
*/
struct  s_node
{
  t_node_type   type;
  int           input;
  int           error_output;
  int           output;
  int           pipe_background;
  t_node        *left;
  t_node        *right;
  t_glist_hs    args;
  t_glist_voidp children;
};

/*
** Creates a new node.
**
** Initializes only the property shared by all the node types.
*/
t_node  *node_new(t_node_type type);

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

#endif /* PARSER_H_ */
