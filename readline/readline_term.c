/*
** readline_term.c for  in /home/bailly_j/rendu/360SH-NoScop3/readline/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sun May 29 17:57:34 2016 Jamy Bailly
** Last update Sun May 29 17:57:34 2016 Jamy Bailly
*/

#include <unistd.h>
#include "../sh.h"
#include "readline.h"

int                     readline_setup_term(int output_fd,
                                            const struct termios *cfg)
{
  char                  *smkx;
  struct termios        new_cfg;

  new_cfg = *cfg;
  new_cfg.c_lflag &= (unsigned int) ~ECHO;
  new_cfg.c_lflag &= (unsigned int) ~ICANON;
  new_cfg.c_cc[VMIN] = 1;
  new_cfg.c_cc[VTIME] = 0;
  smkx = "\x1b[?1h\x1b=";
  if (write(output_fd, smkx, egc_strlen(smkx)) == -1)
    return (-1);
  return (tcsetattr(0, TCSANOW, &new_cfg));
}

int	readline_get_term(struct termios *cfg)
{
  return (tcgetattr(0, cfg));
}

int	readline_restore_term(const struct termios *cfg)
{
  return (tcsetattr(0, TCSANOW, cfg));
}
