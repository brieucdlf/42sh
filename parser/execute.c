/*
** execute.c for 42sh in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Wed May  8 17:56:27 2013 jean gravier
** Last update Fri May 10 18:47:33 2013 jean gravier
*/

#include "parse.h"
#include "42.h"

char	*make_path(char *env_path, char *filename)
{
  char	*path;

  if (env_path != NULL && filename != NULL)
    {
      if ((path = malloc(strlen(env_path) + strlen(filename) + 2)) == NULL)
	return (NULL);
      path = strcpy(path, env_path);
      path = strcat(path, "/");
      path = strcat(path, filename);
      return (path);
    }
  else
    return (NULL);
}

char	*get_path(t_vars *p, char *filename)
{
  int	i;
  char	*path;

  i = 0;
  if (filename != NULL)
    {
      path = make_path(p->path[i], filename);
      while (access(path, F_OK) != 0 && p->path[i] != NULL)
	{
	  i++;
	  free(path);
	  path = make_path(p->path[i], filename);
	}
      return (path);
    }
  else
    return (NULL);
}

void	execute(char *cmd, t_vars *p)
{
  char	*path;
  char	**args;

  if (cmd != NULL)
    {
      args = parse(cmd, " \t");
      path = get_path(p, args[0]);
      execve(path, args, p->env);
      free(args);
      if (path != NULL)
	free(path);
      free(cmd);
    }
}
