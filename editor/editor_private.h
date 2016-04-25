/*
** editor_private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 19:14:33 2016 antoine
** Last update Sun Apr 17 19:14:33 2016 antoine
*/

#ifndef EDITOR_PRIVATE_H
# define EDITOR_PRIVATE_H

#include "editor.h"

struct  s_editor
{
  t_hs                          prompt;
  int                           input;
  int                           output;
  int                           error_output;
  t_editor_completer            completer;
  void                          *completer_data;
  t_editor_completion_printer   printer;
  void                          *printer_data;
  t_editor_colorizer            colorizer;
  void                          *colorizer_data;
};

#endif /* EDITOR_PRIVATE_H */
