/*
** tools.h for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/tools/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Fri May 20 16:03:41 2016 Valentin Pichard
** Last update Sun Jun  5 15:53:20 2016 Valentin Pichard
*/

#ifndef TOOLS_H_
# define TOOLS_H_

# include "../colorize/colorize.h"

/*
** Display segfault error when signal catched
*/
int		check_sigsegv(int status);

/*
** Print string on stdout
*/
void		print_string(const char *string);

/*
** Print string on stderr
*/
void		print_string_error(const char *string);

/*
** Retrun new prompt
*/
t_hs		create_prompt(void);

#endif /* !TOOLS_H_ */
