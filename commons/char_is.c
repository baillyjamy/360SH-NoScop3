/*
** char_is.c for  in /home/jacqui_p/rendu/PSU/360SH-NoScop3/commons/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri May 27 16:47:27 2016 Pierre-Emmanuel Jacquier
** Last update Fri May 27 16:47:27 2016 Pierre-Emmanuel Jacquier
*/

int	is_letter(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int	is_digit(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
