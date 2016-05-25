/*
** get_env.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Wed May 25 16:09:49 2016 Valentin Pichard
** Last update Wed May 25 16:16:00 2016 Valentin Pichard
*/

#include "egc.h"

void		get_env(const char **envp)
{
  STATICS->env = glist_hs_new();
  while (*envp)
    {
      glist_hs_append(STATICS->env, *envp);
      envp++;
    }
}
