/*
** readline_print.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue May 31 21:39:21 2016 Jamy Bailly
** Last update Tue May 31 21:39:21 2016 Jamy Bailly
*/

#include "private.h"

void	readline_print_prompt(t_readline *readline)
{
  egc_printf("%hs", readline->prompt);
}
