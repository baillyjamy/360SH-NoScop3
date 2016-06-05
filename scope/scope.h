/*
** scope.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Jun  5 00:23:43 2016 antoine
** Last update Sun Jun  5 00:23:43 2016 antoine
*/

#ifndef SCOPE_H_
# define SCOPE_H_

# include "../egc.h"

typedef struct          s_scope
{
  t_glist_voidp         variables;
  struct s_scope        *child;
}                       t_scope;

void    scope_init(t_scope *scope);
void    scope_init_from_str_array(t_scope *scope, char **array);

void    scope_set(t_scope *scope, t_hs name, t_hs value);
t_hs    scope_get(t_scope *scope, t_hs name);
t_hs    scope_get_default(t_scope *scope, t_hs name, t_hs default_val);
t_hs    scope_remove(t_scope *scope, t_hs name);
int     scope_contains(t_scope *scope, t_hs name);
void    scope_remove_all(t_scope *scope);
t_hs    scope_to_hs(t_scope *scope);

t_glist_hs      scope_to_glist(t_scope *scope);

void    env_set(t_hs name, t_hs value);
t_hs    env_get(t_hs name);
t_hs    env_get_default(t_hs name, t_hs default_val);
t_hs    env_remove(t_hs name);
int     env_contains(t_hs name);
void    env_remove_all(void);
t_hs    env_to_hs(void);

#endif /* !SCOPE_H_ */
