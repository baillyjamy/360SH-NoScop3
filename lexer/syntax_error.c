/*
** syntax_error.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 08:15:43 2016 antoine
** Last update Thu Apr 28 08:15:43 2016 antoine
*/

#include "lexer.h"

t_syntax_error          *syntax_error_new(t_hs message, t_position position)
{
  t_syntax_error        *e;

  e = EGC_NEW(t_syntax_error);
  e->message = message;
  e->position = position;
  return (e);
}

t_hs                    syntax_error_to_hs(const t_syntax_error *e)
{
  return (hs_format("%hs: %hs", position_to_hs(&e->position), e->message));
}

void    syntax_error_print(const t_syntax_error *e, int file)
{
  hs_puts_file(syntax_error_to_hs(e), file);
}
