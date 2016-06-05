/*
** readline_cfmakeraw.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Jun  4 23:56:26 2016 Jamy Bailly
** Last update Sat Jun  4 23:56:26 2016 Jamy Bailly
*/

#include <sys/termios.h>

void	readline_cfmakeraw(struct termios *t)
{
  t->c_iflag &= ~(IMAXBEL | IGNBRK | BRKINT | PARMRK | ISTRIP |
		  INLCR | IGNCR | ICRNL | IXON);
  t->c_oflag &= ~OPOST;
  t->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
  t->c_cflag &= ~(CSIZE | PARENB);
  t->c_cflag |= CS8;
}
