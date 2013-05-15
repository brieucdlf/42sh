/*
** parse.c for 42sh in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Wed May  8 17:56:37 2013 jean gravier
** Last update Mon May 13 10:30:15 2013 harold fritsch
*/

#include "parse.h"
#include "42.h"

int	get_size(char *str, char *delim)
{
  int	size;

  size = 0;
  if (strtok(str, delim))
    {
      size++;
      while (strtok(NULL, delim))
	size++;
    }
  free(str);
  return (size);
}

char	**parse(char *cmd, char *delim)
{
  int	i;
  int	size;
  char	**cmd_tab;

  i = 0;
  size = get_size(strdup(cmd), delim);
  if ((cmd_tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  cmd_tab[i] = strtok(cmd, delim);
  while (cmd_tab[i] != NULL)
    {
      i++;
      cmd_tab[i] = strtok(NULL, delim);
    }
  return (cmd_tab);
}

void	init_parser(char *cmd, t_vars *p)
{
  int	i;
  char	**cmd_tab;
  char	**temp;

  i = 0;
  if (cmd != NULL)
    {
      cmd_tab = parse(strdup(cmd), ";");
      while (cmd_tab[i] != NULL)
	{
	  temp = parse(strdup(cmd_tab[i]), " \t");
	  if (check_builtin(p, temp) == -1)
	    check_cmd(epur(epur(strdup(cmd_tab[i]), ' '), '\t'), p);
	  free(temp);
	  i++;
	}
      free(cmd_tab);
    }
}
