/*
** redir.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Jun  3 23:45:44 2016 antoine
** Last update Fri Jun  3 23:45:44 2016 antoine
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "private.h"

static t_hs     open_redir_file(t_hs file_name, int *fd, int flags, int mode)
{
  int           err;

  *fd = open(hs_to_str(file_name), flags, mode);
  err = errno;
  if (*fd == -1)
    return (hs_format("%hs: %s.", file_name, strerror(err)));
  return (hs(""));
}

static t_hs     parse_lt(t_token_list **list_pointer, t_redir *redir)
{
  t_token       *t;
  t_hs          word;

  t = parse_token_impl(list_pointer);
  if (!t || !parser_is_word_or_string(t))
    return (hs("Missing name for redirect."));
  word = parser_get_word(t);
  return (open_redir_file(word, &redir->input, O_RDONLY, 0));
}

static t_hs     parse_gt(t_token_list **list_pointer, t_redir *redir)
{
  t_token       *t;
  t_hs          word;
  int           mode;
  int           append;
  int           flags;

  append = parse_token_type_impl(list_pointer, TOKEN_TYPE_GT) != NULL;
  t = parse_token_impl(list_pointer);
  if (!t || !parser_is_word_or_string(t))
    return (hs("Missing name for redirect."));
  word = parser_get_word(t);
  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  flags = O_WRONLY | O_CREAT | O_TRUNC;
  if (append)
    flags |= O_APPEND;
  return (open_redir_file(word, &redir->output, flags, mode));
}

t_hs    parse_redir(t_token_list **list_pointer, t_redir *redir)
{
  t_hs  error;

  while (*list_pointer)
    {
      if (parse_token_type_impl(list_pointer, TOKEN_TYPE_LT))
        {
          error = parse_lt(list_pointer, redir);
          if (hs_length(error))
            return (error);
        }
      else if (parse_token_type_impl(list_pointer, TOKEN_TYPE_GT))
        {
          return (parse_gt(list_pointer, redir));
          if (hs_length(error))
            return (error);
        }
      else
        break ;
    }
  return (hs(""));
}
