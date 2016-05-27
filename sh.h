/*
** sh.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 16:42:03 2016 antoine
** Last update Thu May 26 18:40:28 2016 Valentin Pichard
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

void            statics_init(t_statics *statics);
int		get_env_line(t_hs name, t_hs *value);
int		chdir_error(t_hs path);
int		home_error(t_hs home_path);
void		set_env_line(t_hs variable, t_hs value, short value_is_null);

# ifndef STATICS
#  define STATICS        ((t_statics *)egc_get_statics())
# endif

#endif /* SH_H */
