/*
** tools.h for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/tools/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Fri May 20 16:03:41 2016 Valentin Pichard
** Last update Fri May 20 16:08:09 2016 Valentin Pichard
*/

#ifndef TOOLS_H
# define TOOLS_H

# include "../sh.h"
# include "../colorize/colorize.h"

/*
** Display environment
*/
void		display_environment(const char **envp);

/*
** Display user prompt
*/
void		display_prompt(const char *user);

/*
** Display segfault error when signal catched
*/
void		check_segfault(const int status);

/*
** Print string on stdout
*/
void		print_string(const char *string);

/*
** Print string on stderr
*/
void		print_string_error(const char *string);

#endif /* TOOLS_H */
