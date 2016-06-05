/*
** path.c for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
**
** Made by Antoine Baudrand
** Login   <baudra_a@epitech.net>
**
** Started on  Sat Jun 04 18:53:29 2016 Antoine Baudrand
** Last update Sat Jun 04 19:11:53 2016 Antoine Baudrand
*/

#include "exec.h"
#include "sh.h"

t_glist_hs	get_path_list(void)
{
  t_hs		value;
  t_glist_hs	path;
  const char    *default_path;

  default_path = ("/usr/local/bin:/usr/bin:/bin:"
                  "/usr/local/games:/usr/games:/sbin");
  path = hs_split(hs(default_path), hs(":"));
  if (env_contains(hs("PATH")) == -1)
    return (path);
  value = env_get(hs("PATH"));
  path = hs_split(value, hs(":"));
  return (path);
}

t_hs    concat_path(t_hs left, t_hs right)
{
  char  left_char;

  if (!hs_length(left))
    return (right);
  if (!hs_length(right))
    return (left);
  left_char = hs_get(left, hs_length(left) - 1);
  if (left_char == '/' || hs_get(right, 0) == '/')
    return (hs_concat(left, right));
  return (hs_format("%hs/%hs", left, right));
}

t_hs    find_executable(t_glist_hs *path_list, t_hs cmd_name)
{
  int   i;
  t_hs  path;

  if (!hs_length(cmd_name) || hs_get(cmd_name, 0) == '/')
    return (cmd_name);
  i = -1;
  while (++i < (int)glist_hs_length(path_list))
    {
      path = concat_path(glist_hs_get(path_list, i), cmd_name);
      if (!access(hs_to_str(path), X_OK) && !is_dir(hs_to_str(path)))
        return (path);
    }
  return (hs(""));
}
