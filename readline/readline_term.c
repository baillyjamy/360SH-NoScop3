/*
** readline_term.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun May 29 17:57:34 2016 Jamy Bailly
** Last update Sun May 29 17:57:34 2016 Jamy Bailly
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <term.h>
#include "readline.h"

void	readline_setup_term(struct termios cfg)
{
  char	*smkx;

  cfg.c_lflag &= (unsigned int) ~ECHO;
  cfg.c_lflag &= (unsigned int) ~ICANON;
  cfg.c_cc[VMIN] = 1;
  cfg.c_cc[VTIME] = 0;
  setupterm(NULL, 1, NULL);
  smkx = tigetstr("smkx");
  write(1, smkx, egc_strlen(smkx));
  tcsetattr(0, TCSANOW, &cfg);
}

void	readline_get_term(struct termios *cfg)
{
  tcgetattr(0, cfg);
}

void	readline_restore_term(struct termios *cfg)
{
  tcsetattr(0, TCSANOW, cfg);
}
