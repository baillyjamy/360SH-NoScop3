/*
** private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Jun  3 17:47:53 2016 antoine
** Last update Fri Jun  3 17:47:53 2016 antoine
*/

#ifndef PRIVATE_H_
# define PRIVATE_H_

# include "parser.h"

# define ERROR(message) ((t_parser_result){.error = message, .success = 0})
# define NODE(node)     ((t_parser_result){.node = node, .success = 1})
# define NULL_RESULT    ((t_parser_result){.node = NULL, .success = 1})

#endif /* !PRIVATE_H_ */
