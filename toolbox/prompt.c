/*
** prompt.c for  in /home/bailly_j/rendu/360SH-NoScop3/toolbox/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue May 31 21:13:23 2016 Jamy Bailly
** Last update Tue May 31 21:13:23 2016 Jamy Bailly
*/

#include "../sh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static t_hs	get_hostname(void)
{
  int	fd;
  char	c;
  t_hs	host;

  host = hs("");
  if ((fd = open("/etc/hostname", O_RDONLY)) == -1)
    return (hs("42sh"));
  while (42)
    {
      if (read(fd, &c, 1) == -1)
	return (hs("42sh"));
      if (c == '\n' || c == '\0')
	break;
      host = hs_concat_hs_char(host, c);
    }
  close(fd);
  return (host);
}

static t_hs	format_pwd(t_hs pwd, t_hs home)
{
 if (hs_starts_with(pwd, home))
    return (hs_concat_char_hs('~',
			      hs_slice(pwd, hs_length(home), hs_length(pwd))));
    return (pwd);
}

t_hs	create_prompt(void)
{
  t_hs	user;
  t_hs	host;
  t_hs	pwd;
  t_hs	prompt;

  user = hs("nobody");
  host = hs("42sh");
  pwd = hs("");
  prompt = hs("");
  env_get_variable(hs("USER"), &user);
  env_get_variable(hs("PWD"), &pwd);
  env_get_variable(hs("HOME"), &prompt);
  host = get_hostname();
  pwd = format_pwd(pwd, prompt);
  prompt = hs("");
  prompt = hs_concat(prompt, colorize("red", user));
  prompt = hs_concat(prompt, hs("@"));
  prompt = hs_concat(prompt, host);
  prompt = hs_concat(prompt, hs(":"));
  prompt = hs_concat(prompt, colorize("blue", pwd));
  prompt = hs_concat(prompt, hs("$"));
  return (prompt);
}
