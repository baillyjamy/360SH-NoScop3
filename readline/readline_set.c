/*
** readline_set.c for  in /home/bailly_j/rendu/360SH-NoScop3/editor/
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue May 24 16:19:50 2016 Jamy Bailly
** Last update Tue May 24 16:19:50 2016 Jamy Bailly
*/

#include "private.h"

void	readline_set_tokenizer(t_readline *readline,
			       t_readline_tokenizer tokenizer,
			       void *data)
{
  readline->tokenizer = tokenizer;
  readline->tokenizer_data = data;
}

void	readline_set_completer(t_readline *readline,
			       t_readline_completer completer,
			       void *data)
{
  readline->completer = completer;
  readline->completer_data = data;
}

void	readline_set_completion_printer(t_readline *readline,
					t_readline_completion_printer printer,
					void *data)
{
  readline->printer = printer;
  readline->printer_data = data;
}

void	readline_set_colorizer(t_readline *readline,
			       t_readline_colorizer colorizer,
			       void *data)
{
  readline->colorizer = colorizer;
  readline->colorizer_data = data;
}

void	readline_set_prompt(t_readline *readline, t_hs prompt)
{
  readline->prompt = prompt;
}
