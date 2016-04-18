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

t_editor        *editor_new(int input, int output, int error_output)
{
  t_editor      *editor;

  editor = egc_malloc(sizeof(t_editor));
  return (editor);
}
