/*
** get_position.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Jun  1 16:26:25 2016 antoine
** Last update Wed Jun  1 16:26:25 2016 antoine
*/

#include <assert.h>
#include "private.h"

t_position              lexer_get_position(const char *char_addr)
{
  const char            *string;
  t_position            position;

  position_init(&position);
  string = STATICS->lexer_input_string;
  assert(char_addr >= string);
  while (string < char_addr)
    {
      if (*string == '\n')
        {
          position.line++;
          position.column = 0;
        }
      position.column++;
      position.index++;
      string++;
    }
  return (position);
}
