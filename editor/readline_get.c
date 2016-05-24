/*
** readline_get.c for  in /home/bailly_j/rendu/360SH-NoScop3/editor/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue May 24 00:32:20 2016 Jamy Bailly
** Last update Tue May 24 00:32:20 2016 Jamy Bailly
*/

#include "readline.h"

int	readline_get_input(t_readline *readline)
{
  return (readline->input);
}

int	readline_get_output(t_readline *readline)
{
  return (readline->output);
}

int	readline_get_error_output(t_readline *readline)
{
  return (readline->error_output);
}
