/*
** prompt.c for  in /home/bailly_j/rendu/360SH-NoScop3/toolbox/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue May 31 21:13:23 2016 Jamy Bailly
** Last update Fri Jun  3 16:20:40 2016 Valentin Pichard
*/

#include "../sh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static t_hs	get_hostname(void)
{
  int		fd;
  char		c;
  t_hs		host;

  host = hs("");
  if ((fd = open_file(hs("/etc/hostname"), O_RDONLY)) == -1)
    return (hs("42sh"));
  while (42)
    {
      if (read(fd, &c, 1) == -1)
	{
	  close(fd);
	  return (hs("42sh"));
	}
      if (c == '\n' || c == '\0')
	break ;
      host = hs_concat_hs_char(host, c);
    }
  close(fd);
  return (host);
}

static t_hs	format_pwd(t_hs pwd, t_hs home)
{
  t_hs          rel_path;

  if (hs_starts_with(pwd, home))
    {
      rel_path = hs_slice(pwd, hs_length(home), hs_length(pwd));
      return (hs_concat_char_hs('~', rel_path));
    }
  return (pwd);
}

t_hs		create_prompt(void)
{
  t_hs		user;
  t_hs		host;
  t_hs		pwd;
  t_hs		prompt;

  user = env_get_default(hs("USER"), hs("nobody"));
  pwd = env_get_default(hs("PWD"), hs(""));
  host = get_hostname();
  if (env_contains(hs("HOME")))
    pwd = format_pwd(pwd, env_get(hs("HOME")));
  prompt = hs_format("%hs%hs%hs:%hs$ ",
		     colorize("red bold", user),
		     colorize("red bold", hs("@")),
		     colorize("red bold", host),
		     colorize("blue bold", pwd));
  return (prompt);
}
