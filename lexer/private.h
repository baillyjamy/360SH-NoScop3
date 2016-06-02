/*
** private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri May 20 23:07:27 2016 antoine
** Last update Fri May 20 23:07:27 2016 antoine
*/

#ifndef PRIVATE_H_
# define PRIVATE_H_

# include "../sh.h"
# include "lexer.h"

# define NEXT(string_pointer) ((*string_pointer)++)

typedef struct          s_result
{
  t_token               *token;
  t_syntax_error        *error;
}                       t_result;

# define RESULT_NULL            ((t_result){.token = NULL, .error = NULL})
# define RESULT_TOKEN(t)        ((t_result){.token = t, .error = NULL})
# define RESULT_FROM_ERROR(e)   ((t_result){.token = NULL, .error = e})
# define RESULT_ERROR(msg, cp)  (lexer_create_error(msg, cp))

# define TOKEN_NEW(t, p, s)             token_new(TOKEN_TYPE_##t, p, s)
# define TOKEN_NEW_RANGE(t, b, e)       token_new_range(TOKEN_TYPE_##t, b, e)

#define RESULT_TOKEN_RANGE(t, b, e)     RESULT_TOKEN(TOKEN_NEW_RANGE(t, b, e))

t_result        lexer_create_error(t_hs message, const char *char_addr);

const char      *lexer_get_source(void);

typedef t_result        (*t_lex_function)(const char **string_pointer);

t_result        lex_symbols(const char **string_p);
t_result        lex_d_quotes(const char **string_p);

#endif /* !PRIVATE_H_ */
