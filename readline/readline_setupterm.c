/*
** readline_setupterm.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun Jun  5 19:12:40 2016 Jamy Bailly
** Last update Sun Jun  5 19:12:40 2016 Jamy Bailly
*/

#include <unistd.h>
#include <term.h>

int	readline_setupterm(int output)
{
  if (setupterm(NULL, output, NULL))
    return (-1);
  return (0);
}
