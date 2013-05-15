/*
** set.c for  in /home/fritsc_h//42sh-2017-fritsc_h
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sun May 12 18:17:43 2013 harold fritsch
** Last update Sun May 12 20:31:07 2013 harold fritsch
*/

#include "42.h"

char	*rem_char(char *str, char c)
{
  int	i;
  int	j;

  i = -1;
  while (str && str[++i])
    {
      if (str[i] == c)
	{
	  j = i - 1;
	  while (str[++j])
	    str[j] = str[j + 1];
	}
    }
  return (str);
}

void	set_it(t_vars *p, char *str)
{
  int	i;
  int	nbr_quote;

  nbr_quote = 0;
  i = -1;
  while (str && str[++i])
    if (str[i] == 39)
      ++nbr_quote;
  i = 0;
  while (str && str[i] != '=')
    ++i;
  if ((str[i] == '=') && (str[i + 1] != 39))
    fprintf(stderr, "error while reading .cfg file, check it.\n");
  else if ((nbr_quote == 2) && (str[strlen(str) - 1] == 39))
    {
      str = rem_char(str, 39);
      my_set_env(p, str);
    }
  else
    fprintf(stderr, "error while reading .cfg file, check it.\n");
  free(str);
}
