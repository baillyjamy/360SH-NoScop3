/*
** file.c for  in /Users/pichar_v/Documents/tek1/42SH/360SH-NoScop3/files/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.eu>
**
** Started on  Mon May 30 00:18:20 2016 Valentin Pichard
** Last update Mon May 30 13:25:45 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "file.h"

FILE		*open_file(const t_hs filename, const t_hs mode)
{
  FILE		*fp;

  fp = fopen(hs_to_str(filename), hs_to_str(mode));
  return (fp);
}

void		close_file(FILE *fp)
{
  fclose(fp);
}

void		create_file(const t_hs filename)
{
  close_file(open_file(filename, hs("a")));
}

void		reset_file(const t_hs filename)
{
  close_file(open_file(filename, hs("w")));
}

FILE		*edit_file(const t_hs filename)
{
  FILE		*fp;

  fp = open_file(filename, hs("r+"));
  return (fp);
}
