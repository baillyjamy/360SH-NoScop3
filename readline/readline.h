/*
** readline.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 19:07:49 2016 antoine
** Last update Sat Apr 30 06:51:37 2016 Jamy Bailly
*/

#ifndef READLINE_H_
# define READLINE_H_

# include <termios.h>
# include <sys/ioctl.h>
# include "../egc.h"

struct				s_readline;
typedef struct s_readline	t_readline;

/*
** Returns the index of the begining of the word on the cursor
*/
typedef int             (*t_readline_tokenizer)(t_hs text,
                                                int cursor,
                                                void *data);

/*
** Returs a list of available completions from the given word
*/
typedef t_glist_hs      (*t_readline_completer)(t_hs word, void *data);

/*
** Prints the given completions on the output
*/
typedef void            (*t_readline_completion_printer)(t_glist_hs matches,
                                                         void *data);

/*
** The returned text must have the same length than the given text
*/
typedef t_hs            (*t_readline_colorizer)(t_hs text, void *data);

/*
** Creates a new t_readline
**
** It is useless to initialize all the pointers to NULL since
** egc_malloc() sets all its returned data to zero.
** The default prompt is an empty string
*/
t_readline	*readline_new(int input, int output, int error_output);

int		readline_get_input(t_readline *readline);
int		readline_get_output(t_readline *readline);
int		readline_get_error_output(t_readline *readline);

/*
** Reads a line from the input
**
** If Ctrl+D is pressed in an empty line, -1 is returned.
**
** The line is written at the given address, `line`.
*/
int	readline_read(t_readline *readline, t_hs *line);

/*
** tokenizer: A callback which returns the index of the begining
** of the word on the cursor. Can be NULL.
** data: A pointer to pass to the callback. Can be NULL.
*/
void	readline_set_tokenizer(t_readline *readline,
			       t_readline_tokenizer tokenizer,
			       void *data);

/*
** completer: A callback which returns the completion matches. Can be NULL.
** data: A pointer to pass to the callback. Can be NULL.
*/
void	readline_set_completer(t_readline *readline,
			       t_readline_completer completer,
			       void *data);

/*
** printer: A callback which prints the completion matches. Can be NULL.
** data: A pointer to pass to the callback. Can be NULL.
*/
void	readline_set_completion_printer(t_readline *readline,
					t_readline_completion_printer printer,
					void *data);

/*
** colorizer: A callback which colorizes the given string. Can be NULL.
** data: A pointer to pass to the callback. Can be NULL.
*/
void	readline_set_colorizer(t_readline *readline,
			       t_readline_colorizer colorizer,
			       void *data);

/*
** Save the prompt ine readline module
*/
void	readline_set_prompt(t_readline *readline, t_hs prompt);

/*
** Print the prompt
*/
void	readline_print_prompt(t_readline *readline);

#endif /* !READLINE_H_ */
