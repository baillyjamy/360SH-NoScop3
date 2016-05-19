/*
** sh.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 16:42:03 2016 antoine
** Last update Thu May 19 23:50:18 2016 Valentin Pichard
*/

#ifndef SH_H
# define SH_H

# include "egc.h"

# define GOODBYE(x) exit(x)

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

#endif /* SH_H */
