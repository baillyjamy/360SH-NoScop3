/*
** editor.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 18 08:57:08 2016 antoine
** Last update Mon Apr 18 08:57:08 2016 antoine
*/

#include "editor_private.h"

/*
** It is useless to initialize all the pointers to NULL since
** egc_malloc() sets all its returned data to zero.
*/
t_editor        *editor_new(int input, int output, int error_output)
{
  t_editor      *editor;

  editor = egc_malloc(sizeof(t_editor));
  editor->input = input;
  editor->output = output;
  editor->error_output = error_output;
  editor->prompt = hs_new_empty();
  return (editor);
}
