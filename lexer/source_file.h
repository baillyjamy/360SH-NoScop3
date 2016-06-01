/*
** source_file.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 28 04:16:52 2016 antoine
** Last update Thu Apr 28 04:16:52 2016 antoine
*/

#ifndef SOURCE_FILE_H_
# define SOURCE_FILE_H_

# include "../egc.h"

typedef struct  s_source_file
{
  t_hs          name;
  const char    *content;
}               t_source_file;

/*
** Returns 0 on success, -1 on open() error, -2 on read() error.
*/
int             source_file_read(t_source_file *file,
                                 t_hs file_name);

/*
** Creates a new unnamed file.
** Its name will be "<unknown file>".
*/
void            source_file_init_unnamed(t_source_file *file,
                                         t_hs content);

void            source_file_free(t_source_file *file);

/*
** Reads everything from a given file descriptor.
**
** Returns a string allocated with egc_malloc().
** Returns NULL on error.
*/
char            *read_whole_file(int file_descriptor);

#endif /* !SOURCE_FILE_H_ */
