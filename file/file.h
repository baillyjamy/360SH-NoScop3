/*
** file.h for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sun May 29 22:12:46 2016 Valentin Pichard
** Last update Tue May 31 15:50:10 2016 Valentin Pichard
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
void		create_file(const t_hs filename);

/*
** Reset file lines.
**
** Returns 0 on success or -1 if can't edit file.
*/
void		reset_file(const t_hs filename);

/*
** Add new line at the nline number in the file.
**
** Returns 0 on success or -1 if can't edit file.
*/
int		insert_line(const t_hs filename, t_hs line, const int nline);

/*
** Add new line at the end of the file
*/
int		insert_line_end(const t_hs filename, const t_hs line);

/*
** Add new lines at the end of the file
*/
int		insert_lines(const t_hs filename, const t_glist_hs lines);

/*
** Delete line passed in params in the file
*/
int		delete_line(const t_hs filename, const t_hs line);

/*
** Delete lines passed in params in the file
*/
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
** Read the file line in params and return the line in t_hs.
*/
t_hs		read_line_file(const t_hs filename, int nline);

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

#endif /* !FILE_H_ */
