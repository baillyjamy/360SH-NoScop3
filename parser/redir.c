/*
** redir.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Jun  3 23:45:44 2016 antoine
** Last update Fri Jun  3 23:45:44 2016 antoine
*/

#include "private.h"

static t_hs     open_input_redir(t_hs file_name, t_redir *redir)
{

  redir->input = open(hs_to_str(file_name), O_RDONLY);
  if (redir->input == -1)
    return (hs_format("%hs: No such file or directory.", file_name));
  return (hs(""));
}

static t_hs     parse_lt(t_token_list **list_pointer, t_redir *redir)
{
  t_token       *t;

  t = parse_token_impl(list_pointer);
  if (!t || !parser_is_word_or_string(t))
    return (hs("Missing name for redirect."));
  return (open_input_redir(parser_get_word(t), redir));
}

t_hs            parse_redir(t_token_list **list_pointer, t_redir *redir)
{
  if (parse_token_type_impl(list_pointer, TOKEN_TYPE_LT))
    return (parse_lt(list_pointer, redir));
  return (hs(""));
}
