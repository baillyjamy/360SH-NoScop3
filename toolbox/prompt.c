/*
** prompt.c for  in /home/bailly_j/rendu/360SH-NoScop3/toolbox/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue May 31 21:13:23 2016 Jamy Bailly
** Last update Tue May 31 21:13:23 2016 Jamy Bailly
*/

#include "../sh.h"

t_hs	create_prompt(void)
{
  t_hs	user;
  t_hs	pwd;

  if (env_get_variable(hs("USER"), &user) == -1)
    user = hs_new_empty();
  if (env_get_variable(hs("PWD"), &pwd) == -1)
    pwd = hs_new_empty();
  return (hs_concat(hs_concat_hs_char(user, '@'), pwd));
}
