/*
** files_path.c for  in /Users/pichar_v/Documents/shared/360SH-NoScop3/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Sun Jun  5 21:06:04 2016 Valentin Pichard
** Last update Sun Jun  5 21:07:56 2016 Valentin Pichard
*/

#include "sh.h"

t_hs		path_history(void)
{
  return (hs("./.360sh-noscop3_history"));
}

t_hs		path_rcfile(void)
{
  return (hs("./.360sh-noscop3rc"));
}
