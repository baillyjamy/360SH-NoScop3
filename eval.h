/*
** eval.h for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Jun  3 23:56:13 2016 antoine
** Last update Sat Jun 04 19:49:13 2016 Antoine Baudrand
*/

#ifndef EVAL_H_
# define EVAL_H_

# include "parser/parser.h"

t_bltin_function    find_bltin(t_hs command);
void                get_bltins(t_bltin *bltins);
int                 eval(const t_node *node);

#endif /* !EVAL_H_ */
