/*
** ctrl_d.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Sun May 29 21:23:49 2016 Pierre-Emmanuel Jacquier
** Last update Sun May 29 21:23:49 2016 Pierre-Emmanuel Jacquier
*/

#include "sh.h"

void	ctrl_d(void)
{
  egc_printf("exit\n");
  exitcmd(0);
}
