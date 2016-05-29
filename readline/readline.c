/*
** readline.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 18 08:57:08 2016 antoine
** Last update Sat Apr 30 06:38:25 2016 Jamy Bailly
*/

#include "private.h"

/*
** It is useless to initialize all the pointers to NULL since
** egc_malloc() sets all its returned data to zero.
*/
t_readline      *readline_new(int input, int output, int error_output)
{
  t_readline    *readline;

  readline = egc_malloc(sizeof(t_readline));
  readline->input = input;
  readline->output = output;
  readline->error_output = error_output;
  readline->prompt = hs_new_empty();
  return (readline);
}
