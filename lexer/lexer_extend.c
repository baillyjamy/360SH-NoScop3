/*
** lexer_extend.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/lexer/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Wed Jun  1 15:11:12 2016 Valentin Pichard
** Last update Wed Jun  1 15:14:31 2016 Valentin Pichard
*/

#include <assert.h>
#include "../sh.h"
#include "private.h"

void             	skip_whitespaces(const char **string_p)
{
  while (char_is_whitespace(**string_p))
    NEXT(string_p);
}

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
