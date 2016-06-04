/*
** private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri May 20 23:02:46 2016 antoine
** Last update Fri May 20 23:02:46 2016 antoine
*/

#ifndef PRIVATE_H_
# define PRIVATE_H_

# include "readline.h"

typedef struct	s_capacity
{
  char		*smkx;
  char		*capacity_clear_screen;
  char		*capacity_key_left;
  char		*capacity_key_right;
  char		*capacity_cursor_left;
  char		*capacity_cursor_right;
  char		*capacity_clr_eol;
}		t_capacity;

struct                          s_readline
{
  t_hs                          line;
  t_hs				prompt;
  int				input;
  int				output;
  int				error_output;
  int				cursor_pos;
  t_capacity			*capacity;
  t_readline_tokenizer		tokenizer;
  void				*tokenizer_data;
  t_readline_completer		completer;
  void				*completer_data;
  t_readline_completion_printer printer;
  void				*printer_data;
  t_readline_colorizer		colorizer;
  void				*colorizer_data;
};

typedef int	(*t_readline_ascii)(t_readline *);

void	readline_insert_char(t_readline *readline, char c);

void	readline_delete_char(t_readline *readline);

void	readline_update(t_readline *readline, char *c);

void	readline_update_cursor(const t_readline *readline);

/*
** Returns 0 on success, or -1 on EOF (Ctrl+D).
*/
int	readline_event(t_readline *readline, char *c);

int	readline_ascii_event(t_readline *readline, char c);

int	readline_ctrl_d(t_readline *readline);

int	readline_ctrl_l(t_readline *readline);

/*
** Set terminal configuration
*/
int	readline_setup_term(const struct termios *cfg);

/*
** Get terminal configuration
*/
int	readline_get_term(struct termios *cfg);

/*
** Restore terminal configuration
*/
int	readline_restore_term(const struct termios *cfg);

#endif /* !PRIVATE_H_ */
