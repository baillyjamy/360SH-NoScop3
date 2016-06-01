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
#include <ncurses.h>
#include <term.h>
#include "../readline.h"

#include <string.h>

static int	launch()
{
  t_hs		line;
  t_readline	*readline;

  setupterm(NULL, 1, NULL);
  readline = readline_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
  line = readline_read(readline);
  egc_printf("\nReturn = %hs\n", line);
  return (0);
}

int	main(void)
{
  return (egc_run(0, NULL, NULL, launch));
}
