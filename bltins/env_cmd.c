/*
** env_cmd.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Sun May 29 21:10:04 2016 Pierre-Emmanuel Jacquier
** Last update Sun May 29 21:10:04 2016 Pierre-Emmanuel Jacquier
*/

#include "../sh.h"

int	env_cmd(t_glist_hs *args)
{
  (void) args;
  display_environment();
  return (0);
}
