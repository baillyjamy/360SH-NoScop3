/*
** parser.h for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Jun  2 23:04:47 2016 antoine
** Last update Fri Jun 03 12:01:13 2016 Antoine Baudrand
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "../lexer/lexer.h"
# include "../exec.h"
# include "../sh.h"

typedef enum    e_node_type
{
  NODE_PIPE,
  NODE_COMMAND,
  NODE_PAREN,
  NODE_AND,
  NODE_OR,
  NODE_BACKGROUND,
}               t_node_type;

char const      *node_type_to_str(t_node_type type);

/*
** `type` is the type of the node. The followings types define
** the following properties:
**
** NODE_PIPE:
**      left: The node at the left of the pipeline
**      right: The node at the right of the pipeline
**      pipe_background: True if `|&` was used, false if `|` was used.
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
** <all node types>:
**      type: The type of the node.
**      input, error_output, output: File descriptors.
**
** The other properties are left undefined.
*/
typedef struct  s_node
{
  t_node_type   type;
  t_exec        command;
  int           pipe_background;
  struct s_node *left;
  struct s_node *right;
}               t_node;

/*
** Returns a string describing the node, for debugging purposes.
*/
t_hs    node_to_hs(const t_node *node);
t_node  *add_node(t_node_type type, t_node *left);
void    parse(t_token_list *tokens);

#endif /* PARSER_H_ */
