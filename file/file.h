/*
** file.h for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sun May 29 22:12:46 2016 Valentin Pichard
** Last update Fri Jun  3 18:55:44 2016 Valentin Pichard
*/

#ifndef FILE_H_
# define FILE_H_

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../egc.h"
# include "../parse_int/parse_int.h"

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
int		file_exist(const t_hs filename);
int		file_creator(t_hs path);
int		fshell_init(t_hs path, t_glist_hs *lines);

#endif /* !FILE_H_ */
