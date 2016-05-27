/*
** readline_term.c for  in /home/bailly_j/rendu/360SH-NoScop3/editor/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Fri May 27 18:17:47 2016 Jamy Bailly
** Last update Fri May 27 18:17:47 2016 Jamy Bailly
*/

#include <sys/ioctl.h>
#include <termios.h>

void	readline_setup_term(struct termios cfg)
{
  cfg.c_lflag &= (unsigned int) ~ECHO;
  cfg.c_lflag &= (unsigned int) ~ICANON;
  cfg.c_cc[VMIN] = 0;
  cfg.c_cc[VTIME] = 100;
  ioctl(0, TCSETS, &cfg);
}

void	readline_get_term(struct termios *cfg)
{
  ioctl(0, TCGETS, cfg);
}

void	readline_restore_term(struct termios *cfg)
{
  ioctl(0, TCSETS, cfg);
}
