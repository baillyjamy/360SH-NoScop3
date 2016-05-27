/*
** sh.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 16:42:03 2016 antoine
** Last update Fri May 27 15:56:08 2016 Valentin Pichard
*/

#ifndef SH_H
# define SH_H

# include "egc.h"
# include "toolbox/tools.h"

# define GOODBYE(x) egc_exit(x)

typedef struct  s_test_stats
{
  int           failed_test_count;
  int           total_test_count;
}               t_test_stats;

/*
** `test_stats` is used only by the automated tests.
*/
typedef struct  s_statics
{
  const char    *lexer_input_string;
  t_test_stats  test_stats;
  t_glist_hs	env;
}               t_statics;

/*
** Does not initialize the environment.
*/
void            statics_init(t_statics *statics);

void		env_init(char **env_c_strings);

void		unsetenv_cmd(t_glist_hs *argv);
int		setenv_cmd(t_glist_hs *argv);

int		chdir_error(t_hs path);
int		home_error(t_hs home_path);
void		set_env_line(t_hs variable, t_hs value, short value_is_null);
int		env_variable_exists(t_hs name);
void		env_variable_creator(t_hs name, t_hs value);
int		get_env_line(t_hs name, t_hs *value);
void		unset_env(t_hs name);

# ifndef STATICS
#  define STATICS        ((t_statics *)egc_get_statics())
# endif

#endif /* SH_H */
