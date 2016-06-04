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

void                    readline_setup_term(const struct termios *cfg)
{
  char                  *smkx;
  struct termios        new_cfg;

  new_cfg = *cfg;
  new_cfg.c_lflag &= (unsigned int) ~ECHO;
  new_cfg.c_lflag &= (unsigned int) ~ICANON;
  new_cfg.c_cc[VMIN] = 1;
  new_cfg.c_cc[VTIME] = 0;
  smkx = "\x1b[?1h\x1b=";
  write(1, smkx, egc_strlen(smkx));
  tcsetattr(0, TCSANOW, &new_cfg);
}

void	readline_get_term(struct termios *cfg)
{
  tcgetattr(0, cfg);
}

void	readline_restore_term(const struct termios *cfg)
{
  tcsetattr(0, TCSANOW, cfg);
}
