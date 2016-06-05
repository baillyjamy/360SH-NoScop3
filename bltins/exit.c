/*
** exit.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/bltin/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Sun May 29 21:03:53 2016 Pierre-Emmanuel Jacquier
** Last update Sun Jun  5 10:28:11 2016 Valentin Pichard
*/

#include <unistd.h>
#include "../readline/readline.h"
#include "../parse_int/parse_int.h"
#include "../sh.h"

void	print_exit(int status)
{
  GOODBYE(status);
}

static int	check_syntax(t_hs value)
{
  int		i;
  char          c;
  long		val;

  i = -1;
  while (++i < (int)hs_length(value))
    {
      c = hs_get(value, i);
      if (!char_is_digit(c))
	{
	  egc_fprintf(STDERR_FILENO, "exit: Expression Syntax.\n");
	  return (1);
	}
    }
  parse_int(hs_to_str(value), &val);
  print_exit(val);
  return (1);
}

int	exit_cmd(t_glist_hs *argv)
{
  if (glist_hs_length(argv) > 2)
    return (egc_fprintf(STDERR_FILENO, "exit: Expression Syntax.\n"));
  if (glist_hs_length(argv) == 1)
    print_exit(0);
  if (glist_hs_length(argv) == 2)
    return (check_syntax(glist_hs_get(argv, 1)));
  return (0);
}
