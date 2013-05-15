/*
** add_rem_show_env.c for  in /home/fritsc_h//42sh-2017-fritsc_h
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Wed May  8 18:00:20 2013 harold fritsch
** Last update Thu May  9 10:45:55 2013 harold fritsch
*/

#include "42.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while ((tab != NULL) && (tab[i] != NULL))
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}

int	add_var(t_vars *p, char *data)
{
  int	i;
  int	len;
  char	**new_env;

  len = tab_size(p->env);
  data = correctdata(data);
  if ((new_env = malloc(sizeof(*new_env) * (len + 3))) == NULL)
    return (1);
  i = -1;
  while (++i < len)
    new_env[i] = strdup(p->env[i]);
  new_env[i] = data;
  new_env[i + 1] = NULL;
  free_tab(p->env);
  p->env = new_env;
  return (0);
}

int	my_set_env(t_vars *p, char *data)
{
  if (check_existing_variable(p, data) == 0)
    rem_var(p, data);
  if (add_var(p, data) != 0)
    { 
      fprintf(stderr, "error while setting variable\n");
      return (1);
    }
  return (0);
}

char	**mk_new_env(t_vars *p, char **tmpenv)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((tmpenv = malloc(sizeof(*tmpenv) * (p->taille_env + 1))) == NULL)
    return (NULL);
  while (j < p->taille_env)
    {
      if (p->env[j] != NULL)
	tmpenv[i++] = p->env[j];
      ++j;
    }
  tmpenv[i] = NULL;
  return (tmpenv);
}

int	rem_var(t_vars *p, char *data)
{
  int	i;

  p->taille_env = tab_size(p->env);
  if (check_existing_variable(p, data) != 0)
    return (-1);
  i = p->var_position + 1;
  while (i < p->taille_env - 1)
    {
      p->env[i] = p->env[i + 1];
      ++i;
    }
  p->env[i] = NULL;
  return (0);
}
