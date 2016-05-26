/*
** main.c for  in /home/bailly_j/rendu/360SH-NoScop3/editor/test/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed May 25 14:54:45 2016 Jamy Bailly
** Last update Wed May 25 14:54:45 2016 Jamy Bailly
*/

#include <unistd.h>
#include "../readline.h"

static int	launch()
{
  t_hs		name;
  t_readline	*readline;

  readline = readline_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
  name = readline_read(readline);
  egc_printf(" %hs!\n", name);
  return (0);
}

int	main(void)
{
  return (egc_run(0, NULL, launch));
}
