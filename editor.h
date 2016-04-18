/*
** editor.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 19:07:49 2016 antoine
** Last update Sun Apr 17 19:07:49 2016 antoine
*/

#ifndef EDITOR_H
# define EDITOR_H

# include "egc/include/egc.h"

struct                          s_editor;
typedef struct s_editor         t_editor;

/*
** Returs a list of available completions from the given text
*/
typedef t_glist_hs      (*t_editor_completer)(t_hs text, void *data);

typedef void            (*t_editor_completion_printer)(t_glist_hs matches,
                                                       void *data);

/*
** The returned text must have the same length than the given text
*/
typedef t_hs            (*t_editor_colorizer)(t_hs text, void *data);

/*
** Creates a new t_editor
**
** The default prompt is an empty string
*/
t_editor                *editor_new(int input, int output, int error_output);

/*
** Reads a line from the input
*/
t_hs                    editor_read(t_editor *editor);

/*
** completer: A callback which returns the completion matches. Can be NULL.
** data: A pointer to pass to the callback. Can be NULL.
*/
void    editor_set_completer(t_editor *editor,
                             t_editor_completer completer,
                             void *data);

/*
** printer: A callback which prints the completion matches. Can be NULL.
** data: A pointer to pass to the callback. Can be NULL.
*/
void    editor_set_completion_printer(t_editor *editor,
                                      t_editor_completion_printer printer,
                                      void *data);

/*
** colorizer: A callback which colorizes the given string. Can be NULL.
** data: A pointer to pass to the callback. Can be NULL.
*/
void    editor_set_colorizer(t_editor *editor,
                             t_editor_colorizer colorizer,
                             void *data);

/*
** Returns 0 on success or -1 if the given prompt is invalid.
*/
int     editor_set_prompt(t_editor *editor, t_hs prompt);

void    editor_clear_history(t_editor *editor);

#endif /* EDITOR_H */
