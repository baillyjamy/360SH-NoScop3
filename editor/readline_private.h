/*
** readline_private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 19:14:33 2016 antoine
** Last update Sat Apr 30 06:49:54 2016 Jamy Bailly
*/

#ifndef READLINE_PRIVATE_H
# define READLINE_PRIVATE_H

#include "readline.h"

struct	s_readline
{
  t_hs				prompt;
  int				input;
  int				output;
  int				error_output;
  t_readline_completer		completer;
  void				*completer_data;
  t_readline_completion_printer	printer;
  void				*printer_data;
  t_readline_colorizer		colorizer;
  void				*colorizer_data;
};

#endif /* READLINE_PRIVATE_H */
