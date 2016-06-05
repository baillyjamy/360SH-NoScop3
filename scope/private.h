/*
** private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 00:24:14 2016 antoine
** Last update Sun Jun  5 00:24:14 2016 antoine
*/

#ifndef PRIVATE_H_
# define PRIVATE_H_

# include "scope.h"

typedef struct  s_variable
{
  t_hs          name;
  t_hs          value;
}               t_variable;

t_variable      *variable_new(t_hs name, t_hs value);
t_variable      *variable_from_hs(t_hs string);
t_hs            variable_to_hs(const t_variable *variable);

t_variable      *scope_get_variable(t_scope *scope, t_hs name);
void            scope_add_variable(t_scope *scope, t_variable *var);

#endif /* !PRIVATE_H_ */
