/*
** node.c for parser in /home/antoine/360SH-NoScop3/parser
** 
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
** 
** Started on  Fri Jun 03 11:50:59 2016 Antoine Baudrand
** Last update Fri Jun 03 12:02:05 2016 Antoine Baudrand
*/

#include <unistd.h>
#include "../egc.h"
#include "parser.h"

t_node      *add_node(t_node_type type, t_node *left)
{
  t_node    *new;

  new = EGC_NEW(t_node);
  new->type = type;
  new->command.stdin_fd = STDIN_FILENO;
  new->command.stdout_fd = STDOUT_FILENO;
  new->command.stderr_fd = STDERR_FILENO;
  new->pipe_background = 0;
  new->left = left;
  new->right = NULL;
  return (new);
}
