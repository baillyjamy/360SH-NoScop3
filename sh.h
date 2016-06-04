/*
** sh.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 16:42:03 2016 antoine
** Last update Fri Jun  3 19:00:02 2016 Valentin Pichard
*/

#ifndef SH_H_
# define SH_H_

# include <termios.h>
# include "egc.h"
# include "./toolbox/tools.h"
# include "file/file.h"

# define GOODBYE(x) egc_exit(x)

typedef struct  s_test_stats
{
  int           failed_test_count;
  int           total_test_count;
}               t_test_stats;

/*
** `test_stats` is used only by the automated tests.
*/
typedef struct  	s_statics
{
  const char    	*lexer_input_string;
  t_test_stats  	test_stats;
  t_glist_hs		env;
}               	t_statics;

/*
** Initializes the statics variables, with an empty environment.
*/
void            statics_init(t_statics *statics);

/*
** Initializes the environment from an array of strings.
**
** Should be called after statics_init().
*/
void		env_init(char **env_c_strings);

/*
** Find an environment variable.
**
** Write the variable value at the given address.
** Returns 0 on success or -1 if the variable is not found.
**
*/
int		env_get_variable(t_hs name, t_hs *value_pointer);

/*
** Sets an environment variable.
**
** A new variable is created if it doesn't exists.
*/
void		env_set_variable(t_hs name, t_hs value);

/*
** Removes an environment variable.
**
** Does nothing if the variable doesn't exist.
*/
void		env_remove_all_variable(void);
void		env_remove_variable(t_hs name);

/*
** Returns 1 if there is an environment variable with the given name.
*/
int		env_variable_exists(t_hs name);

void		env_create_variable(t_hs name, t_hs value);

int		chdir_error(t_hs path);
int		home_error(t_hs home_path);
void		print_exit(int status);

/*
** built-in functions
*/
typedef int     (*t_bltin_function)(t_glist_hs *args);

typedef struct          s_bltin
{
  const char            *name;
  t_bltin_function      function;
}                       t_bltin;

int		env_cmd(t_glist_hs *argv);
int		cd_cmd(t_glist_hs *argv);
int		exit_cmd(t_glist_hs *argv);
int		echo_cmd(t_glist_hs *argv);
int		setenv_cmd(t_glist_hs *argv);
int		unsetenv_cmd(t_glist_hs *argv);

/*
** Rcfile functions
*/
int		get_rcfile(t_glist_hs *to_exec);
int		get_history(t_glist_hs *history);

/*
** Return 0 if success and -1 if not
*/
int	expand_variables(t_hs input, t_hs *result);

# ifndef STATICS
#  define STATICS       ((t_statics *)egc_get_statics())
# endif

#endif /* !SH_H_ */
