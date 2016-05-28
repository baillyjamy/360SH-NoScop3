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

  result = lex(hs(""));
  ASSERT(result.error == NULL);
  ASSERT(result.tokens != NULL);
}
