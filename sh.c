/*
** shell.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/src/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Fri Apr 22 17:49:55 2016 Valentin Pichard
** Last update Fri Apr 22 17:50:26 2016 Valentin Pichard
*/

#include <string.h>
#include "sh.h"

void            statics_init(t_statics *s)
{
  s->test_stats.failed_test_count = 0;
  s->test_stats.total_test_count = 0;
  s->lexer_input_string = NULL;
}
