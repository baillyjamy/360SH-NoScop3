/*
** lexer.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 04:19:43 2016 antoine
** Last update Wed Jun  1 15:14:47 2016 Valentin Pichard
*/

#ifndef LEXER_H_
# define LEXER_H_

# include "../egc.h"
# include "position.h"

/*
** Don't reorder these fields unless you change token_type_to_str() too
*/
typedef enum    e_token_type
{
  TOKEN_TYPE_AND,
  TOKEN_TYPE_AND_AND,
  TOKEN_TYPE_GT,
  TOKEN_TYPE_HEREDOC,
  TOKEN_TYPE_LEFT_PAREN,
  TOKEN_TYPE_LT,
  TOKEN_TYPE_PIPE,
  TOKEN_TYPE_PIPE_PIPE,
  TOKEN_TYPE_RIGHT_PAREN,
  TOKEN_TYPE_SEMICOLON,
  TOKEN_TYPE_S_QUOTES,
  TOKEN_TYPE_D_QUOTES,
  TOKEN_TYPE_WORD,
}               t_token_type;

typedef struct  s_token
{
  t_token_type  type;
  t_position    position;
  t_hs          source;
  /*
  union
  {
    t_hs                string_value;
  };
  */
}               t_token;

t_token *token_new(t_token_type type, t_position position, t_hs source);

t_token *token_new_range(t_token_type type,
                         const char *begin,
                         const char *end);

t_hs    token_to_hs(const t_token *token);

const char      *token_type_to_str(t_token_type type);

# define TOKEN_NEW(t, p, s)             token_new_range(TOKEN_TYPE_##t, p, s)
# define TOKEN_NEW_RANGE(t, b, e)       token_new_range(TOKEN_TYPE_##t, b, e)

t_position      lexer_get_position(const char *char_address);

typedef struct  s_syntax_error
{
  t_hs          message;
  t_position    position;
}               t_syntax_error;

t_syntax_error  *syntax_error_new(t_hs message, t_position pos);
t_hs            syntax_error_to_hs(const t_syntax_error *e);
void            syntax_error_print(const t_syntax_error *e,
                                   int output_file);

typedef struct          s_token_list
{
  t_token               *token;
  struct s_token_list   *next;
}                       t_token_list;

t_token_list    *token_list_new(t_token *token, t_token_list *next);
void            token_list_add(t_token_list **list_pointer, t_token *token);
t_token_list    *token_list_last(t_token_list *token_list);
t_hs            token_list_to_hs(const t_token_list *tokens);

typedef struct          s_lexer_result
{
  t_token_list          *tokens;
  t_syntax_error        *error;
}                       t_lexer_result;

t_lexer_result  lex(t_hs string);
void            skip_whitespaces(const char **string_p);
t_position      lexer_get_position(const char *char_addr);

#endif /* !LEXER_H_ */
