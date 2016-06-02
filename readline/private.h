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

# define RDC readline->capacity

# define CAPACITY_CLEAR_SCREEN clear
# define CAPACITY_KEY_LEFT kcub1
# define CAPACITY_KEY_RIGHT kcuf1
# define CAPACITY_CURSOR_LEFT cub1
# define CAPACITY_CURSOR_RIGHT cuf1
# define CAPACITY_CLR_EOL el

typedef struct	s_capacity
{
  char		*smkx;
  char		*CAPACITY_CLEAR_SCREEN;
  char		*CAPACITY_KEY_LEFT;
  char		*CAPACITY_KEY_RIGHT;
  char		*CAPACITY_CURSOR_LEFT;
  char		*CAPACITY_CURSOR_RIGHT;
  char		*CAPACITY_CLR_EOL;
}		t_capacity;

struct	s_readline
{
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

void	readline_setup_term(struct termios cfg);

void	readline_get_term(struct termios *cfg);

void	readline_restore_term(struct termios *cfg);

t_hs	readline_insert_char(t_capacity *capacity,
			     t_hs line,
			     char c,
			     int *cursor_pos);

t_hs	readline_delete_char(t_capacity *capacity, t_hs line, int *cursor_pos);

t_hs	readline_update(t_capacity *capacity,
			t_hs line,
			char c,
			int *cursor_pos);

void	readline_update_cursor(t_capacity *capacity,
			       int *cursor_pos,
			       size_t len_line);

void	readline_event(t_capacity *capacity,
		       char *c_str,
		       int *cursor_pos,
		       int len_line);

void	readline_ctrl_event(t_capacity *capacity, char c);

#endif /* !PRIVATE_H_ */
