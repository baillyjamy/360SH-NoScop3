/*
** private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri May 20 23:02:46 2016 antoine
** Last update Fri May 20 23:02:46 2016 antoine
*/

#ifndef READLINE_PRIVATE_H
# define READLINE_PRIVATE_H

# include "readline.h"

struct	s_readline
{
  t_hs				prompt;
  int				input;
  int				output;
  int				error_output;
  t_readline_tokenizer		tokenizer;
  void				*tokenizer_data;
  t_readline_completer		completer;
  void				*completer_data;
  t_readline_completion_printer printer;
  void				*printer_data;
  t_readline_colorizer		colorizer;
  void				*colorizer_data;
};

#endif /* READLINE_PRIVATE_H */
