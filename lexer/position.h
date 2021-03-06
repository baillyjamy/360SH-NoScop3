/*
** position.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 04:16:59 2016 antoine
** Last update Thu Apr 28 04:16:59 2016 antoine
*/

#ifndef POSITION_H_
# define POSITION_H_

# include "../egc.h"
# include "source_file.h"

/*
** line: 1-based line number
** column: 1-based column number
*/
typedef struct  s_position
{
  int           index;
  int           line;
  int           column;
}               t_position;

/*
** Initialize a new position.
** Character index 0, first line, first column.
*/
void            position_init(t_position *position);

t_hs            position_to_hs(const t_position *position);

void            position_print(const t_position *position,
                               int output_file_descriptor);

#endif /* !POSITION_H_ */
