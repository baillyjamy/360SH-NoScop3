/*
** position.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 12:53:13 2016 antoine
** Last update Sat Apr 16 13:49:10 2016 Valentin Pichard
*/

#include "position.h"

void            position_init(t_position *position,
                              t_source_file *source_file)
{
  position->file = source_file;
  position->index = 0;
  position->line = 1;
  position->column = 0;
}

t_hs            position_to_hs(const t_position *position)
{
  return hs_format("%s:%d:%d",
                   position->file->name,
                   position->line,
                   position->column);
}

void            position_print(const t_position *position, int file)
{
  hs_print_file(position_to_hs(position), file);
}
