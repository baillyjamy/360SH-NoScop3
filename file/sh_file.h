/*
** sh_file.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Jun  4 12:07:15 2016 antoine
** Last update Sat Jun  4 12:07:15 2016 antoine
*/

#ifndef SH_FILE_H_
# define SH_FILE_H_

# include <unistd.h>
# include "../egc.h"

/*
** Create a new file using the filename in params.
**
** Returns 0 on success or -1 if can't create file.
*/
int		create_file(const t_hs filename);

/*
** Reset file lines.
**
** Returns 0 on success or -1 if can't edit file.
*/
int		reset_file(const t_hs filename);

/*
** Add new line at the end of the file
**
** Returns 0 on success or -1 if can't edit file.
*/
int		insert_line(const t_hs filename, const t_hs line);
int		insert_lines(const t_hs filename, const t_glist_hs lines);

/*
** Delete line passed in params in the file
*/
int		delete_line(const t_hs filename, const t_hs line);
int		delete_lines(const t_hs filename, const t_glist_hs lines);

/*
** Check if the file exist or not.
**
** Returns 0 on success or -1 if can't found the file.
*/
int		file_exist_and_edit(const t_hs filename);

/*
** Read all the file and return all lines in t_glist_hs.
*/
int		read_file(const t_hs filename, t_glist_hs *lines);

/*
** Check if the line exist in the file.
**
** Returns 0 on success or -1 if the line dont exist.
*/
int		line_exist(const t_hs filename, const t_hs line);

/*
** Check if the lines exist in the file.
**
** Returns 0 on success or -1 if all the lines dont exist.
*/
int		lines_exist(const t_hs filename, const t_glist_hs lines);

int		open_file(const t_hs pathname, int mode);
void		close_file(int fd);
int		edit_file(const t_hs filename);
ssize_t		get_file_length(const t_hs filename);

/*
** Returns 1 if the file exists, 0 othewise.
*/
int		file_exist(const t_hs filename);

/*
** Return 1 if the file is a directory
*/
int             is_dir(char *file_name);

int		file_creator(t_hs path);
int		fshell_init(t_hs path, t_glist_hs *lines);

#endif /* !SH_FILE_H_ */
