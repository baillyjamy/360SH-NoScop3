/*
** private.h for parser in /home/antoine/360SH-NoScop3/parser
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Jun  3 17:47:53 2016 antoine
** Last update Sat Jun 04 19:45:30 2016 Antoine Baudrand
*/

#ifndef PRIVATE_H_
# define PRIVATE_H_

# include "parser.h"

/*
** Creates a new node.
**
** Initializes only the property shared by all the node types.
*/
t_node  *node_new(t_node_type type, const t_redir *redir);

void    parser_redir_init(t_redir *redir);

# define ERROR(message) ((t_parser_result){.error = message, .success = 0})
# define NODE(node_)    ((t_parser_result){.node = node_, .success = 1})
# define NULL_RESULT    ((t_parser_result){.node = NULL, .success = 1})

typedef struct  s_token_result
{
  t_hs          error;
  t_token       *token;
}               t_token_result;

# define TOKEN_RESULT_IS_ERR(r)         (hs_length((r).error))
# define TOKEN_RESULT_IS_NULL(r)        (!hs_length((r).error) && !(r).token)

# define TOKEN_RESULT_NULL      (t_token_result){.error = hs(""), .token = 0}

/*
** Returns an empty string on success, or a error message on failure.
*/
t_hs            parse_redir(t_token_list **list_pointer, t_redir *redir);

t_hs            parser_get_word(t_token *token);
int             parser_is_word_or_string(t_token *token);
t_token         *parse_token_impl(t_token_list **list_pointer);
t_token         *parse_token_type_impl(t_token_list **list_pointer,
                                       t_token_type t);
t_token_result  parse_token(t_token_list **list_pointer, t_redir *redir);
int             parse_word_or_string(t_token_list **list_pointer,
                                     t_hs *result,
                                     t_redir *redir);
t_token_result  parse_token_type(t_token_list **list_pointer,
                                 t_token_type type,
                                 t_redir *redir);

#endif /* !PRIVATE_H_ */
