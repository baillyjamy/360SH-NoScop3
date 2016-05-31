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
  int				cursor_pos;
  t_readline_tokenizer		tokenizer;
  void				*tokenizer_data;
  t_readline_completer		completer;
  void				*completer_data;
  t_readline_completion_printer printer;
  void				*printer_data;
  t_readline_colorizer		colorizer;
  void				*colorizer_data;
};

void	readline_setup_term(struct termios cfg);

void	readline_get_term(struct termios *cfg);

void	readline_restore_term(struct termios *cfg);

t_hs	readline_insert_char(t_hs line, char c, int *cursor_pos);

t_hs	readline_delete_char(t_hs line, int *cursor_pos);

t_hs	readline_update(t_hs line, char c, int *cursor_pos);

void	readline_event(char *c_str, int *cursor_pos);

#endif /* READLINE_PRIVATE_H */
