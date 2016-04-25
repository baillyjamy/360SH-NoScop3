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
#include "../egc/include/egc.h"

void            position_init(t_position *position,
                              t_source_file *source_file)
{
  position->file = source_file;
  position->index = 0;
  position->line = 1;
  position->column = 0;
}

void            position_print(const t_position *position, int file)
{
  egc_fprintf(file,
              "%s:",
              position->file->name);
  egc_fprintf(file,
              "%d:%d",
              position->line,
              position->column);
}
