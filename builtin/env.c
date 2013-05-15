/*
** env.c for  in /home/fritsc_h//42sh/builtin
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Tue Apr 23 00:19:20 2013 harold fritsch
** Last update Thu May  9 12:14:34 2013 harold fritsch
*/

#include "42.h"

int	tab_size(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

char	*correctdata(char *data)
{
  int	i;
  int	check;
  char	*tmp;

  i = 0;
  check = 0;
  while ((data[i]) && (check == 0))
    if (data[i++] == '=')
      check = 1;
  if (check != 1)
    {
      check = strlen(data);
      if ((tmp = malloc(sizeof(*tmp) * (check + 2))) == NULL)
	return (NULL);
      i = -1;
      while (++i < check)
	tmp[i] = data[i];
      tmp[i++] = '=';
      tmp[i] = '\0';
      return (tmp);
    }
  return (strdup(data));
}

void	my_env(t_vars *p)
{
  int	i;

  i = 0;
  while (p->env[i] != NULL)
    {
      printf("%s\n", p->env[i]);
      ++i;
    }
}

int	check_existing_variable(t_vars *p, char *var_name)
{
  int	len;
  int	i;
  char	*tmp;

  i = 0;
  p->var_position = 0;
  if (var_name != NULL)
    {
      len = 0;
      tmp = correctdata(var_name);
      while ((tmp[len]) && (tmp[len] != '='))
	++len;
      while ((p->env) && (p->env[i] != NULL))
	{
	  if ((strncmp(tmp, p->env[i], (len + 1))) == 0)
	    {
	      p->var_position = i - 1;
	      free(tmp);
	      return (0);
	    }
	  ++i;
	}
      free(tmp);
    }
  return (-1);
}
