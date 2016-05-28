/*
** test_lexer.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat May 28 08:19:24 2016 antoine
** Last update Sat May 28 08:19:24 2016 antoine
*/

#include "test.h"
#include "../../lexer/lexer.h"

void                    test_suite_lexer(void)
{
  t_lexer_result        result;
  t_token               *token;

  result = lex(hs(""));
  ASSERT(result.error == NULL);
  ASSERT(result.tokens == NULL);

  result = lex(hs("this_is-a/single,Word"));
  ASSERT(result.error == NULL);
  ASSERT(result.tokens != NULL);
  token = result.tokens->token;
  ASSERT(hs_equals(hs("this_is-a/single,Word"), token->source));
  ASSERT(result.tokens->next == NULL);
}
