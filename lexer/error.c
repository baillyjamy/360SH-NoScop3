/*
** error.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 15:47:39 2016 antoine
** Last update Thu Apr 28 15:47:39 2016 antoine
*/

#include "private.h"

t_result        lexer_create_error(t_hs msg, const char *char_addr)
{
  t_result      r;

  r.token = NULL;
  r.error = syntax_error_new(msg, lexer_get_position(char_addr));
  return (r);
}
