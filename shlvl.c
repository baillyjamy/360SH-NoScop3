/*
** shlvl.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Sun Jun  5 01:34:17 2016 Pierre-Emmanuel Jacquier
** Last update Sun Jun  5 01:34:17 2016 Pierre-Emmanuel Jacquier
*/

#include "sh.h"

void		update_shell_level(void)
{
  t_hs		value;
  unsigned long	sh_value;

  value = hs("");
  if (env_get_variable(hs("SHLVL"), &value))
    {
      env_set_variable(hs("SHLVL"), hs("1"));
      return ;
    }
  if (parse_uint(hs_to_str(value), &sh_value))
    sh_value = 0;
  sh_value++;
  env_set_variable(hs("SHLVL"), hs_format("%d", sh_value));
}
