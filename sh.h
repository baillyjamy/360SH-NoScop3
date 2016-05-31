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

void		unsetenv_cmd(t_glist_hs *argv);
int		setenv_cmd(t_glist_hs *argv);

int		chdir_error(t_hs path);
int		home_error(t_hs home_path);
void		ctrl_d(void);
/*
** parse_int
*/
int     parse_int(const char *string, long *result_pointer);
/*
** built-in fonctions
*/
void		envcmd(void);
int		cdcmd(t_glist_hs *argv);
int		exitcmd(t_glist_hs *argv);
int		echocmd(t_glist_hs *argv);
int		setenv_cmd(t_glist_hs *argv);
void		unsetenv_cmd(t_glist_hs *argv);

# ifndef STATICS
#  define STATICS        ((t_statics *)egc_get_statics())
# endif

#endif /* SH_H */
