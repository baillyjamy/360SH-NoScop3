/*
** test_lexer_symbols.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Jun  2 16:32:09 2016 antoine
** Last update Thu Jun  2 16:32:09 2016 antoine
*/

#include "test.h"
#include "../../lexer/lexer.h"

static void             test_0(void)
{
  t_lexer_result        result;

  result = lex(hs("<> && | ||"));
  ASSERT(result.error == NULL);
  ASSERT(hs_equals(token_list_to_hs(result.tokens),
                   hs("<lt <><gt >><and_and &&><pipe |><pipe_pipe ||>")));
}

static void             test_1(void)
{
  t_lexer_result        result;

  result = lex(hs("a>b||c"));
  ASSERT(result.error == NULL);
  ASSERT(hs_equals(token_list_to_hs(result.tokens),
                   hs("<word a><gt >><word b><pipe_pipe ||><word c>")));
}

static void             test_d_quotes(void)
{
  t_lexer_result        result;

  result = lex(hs("\"lol\""));
  ASSERT(result.error == NULL);
  ASSERT(hs_equals(token_list_to_hs(result.tokens),
                   hs("<d_quotes \"lol\" \"lol\">")));
}

void    test_suite_lexer_symbols(void)
{
  test_0();
  test_1();
  test_d_quotes();
}
