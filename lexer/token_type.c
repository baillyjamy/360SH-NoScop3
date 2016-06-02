/*
** token_type.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Jun  2 15:48:52 2016 antoine
** Last update Thu Jun  2 15:48:52 2016 antoine
*/

#include <assert.h>
#include "private.h"

static void     skip_word(const char **string_pointer)
{
  while (**string_pointer)
    (*string_pointer)++;
}

const char      *token_type_to_str(t_token_type type)
{
  const char    *string;

  string = ("and\0and_and\0gt\0heredoc\0left_paren\0lt\0pipe\0pipe_pipe\0"
            "right_paren\0semicolon\0s_quotes\0d_quotes\0word\0\0");
  while (*string)
    {
      if (!type)
        return (string);
      type--;
      skip_word(&string);
      string++;
    }
  assert(0);
}
