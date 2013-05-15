/*
** extract_path.c for  in /home/fritsc_h//42sh-2017-fritsc_h/path
**
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Wed May  1 14:34:36 2013 harold fritsch
** Last update Thu May  9 11:05:59 2013 harold fritsch
*/

#include "42.h"

int	ct_char(char *str, char character)
{
  int	i;
  int	nbr_char;

  i = 0;
  nbr_char = 0;
  while (str && str[i])
    {
      if (str[i] == character)
	++nbr_char;
      ++i;
    }
  return (nbr_char);
}

int	extract_path(t_vars *p)
{
  int	i;

  i = 0;
  if (p->env_is_set == 1)
    {
      if ((check_existing_variable(p, "PATH")) == 0)
	{
	  p->buf_path = strdup(&p->env[p->var_position + 1][5]);
	  if ((p->path = malloc(sizeof(p->path) *
				(ct_char(p->buf_path, ':') + 2))) == NULL)
	    return (1);
	  p->path[i] = strtok(p->buf_path, ":");
	  ++i;
	  while ((p->path[i] = strtok(NULL, ":")) != NULL)
	    ++i;
	  p->path[i] = NULL;
	}
      return (0);
    }
  return (1);
}
