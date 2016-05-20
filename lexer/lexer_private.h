/*
** lexer_private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 07:56:54 2016 antoine
** Last update Thu Apr 28 07:56:54 2016 antoine
*/

#ifndef LEXER_PRIVATE_H
# define LEXER_PRIVATE_H

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
# define RESULT_ERROR(msg, pos) (lex_create_error(msg, pos))

t_result                lexer_create_error(const char *msg,
                                           const char *position);

const char              *lexer_get_source(void);

typedef t_result        (*t_lex_function)(const char **string_pointer);

#endif /* LEXER_PRIVATE_H */
