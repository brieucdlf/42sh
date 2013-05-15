/*
** check_cmd.c for 42sh in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Wed May  8 17:56:01 2013 jean gravier
** Last update Mon May 13 19:53:51 2013 jean gravier
*/

#include "parse.h"

int	check_filename(t_vars *p, char *filename)
{
  int	i;
  char	*path;

  i = 0;
  if (filename != NULL)
    {
      path = make_path(p->path[i], filename);
      while (p->path[i] != NULL)
	{
	  if (access(path, F_OK) == 0)
	    return (0);
	  i++;
	  free(path);
	  if (p->path[i] != NULL)
	    path = make_path(p->path[i], filename);
	}
      return (-1);
    }
  else
    return (-1);
}

char	*get_filename(char *cmd)
{
  strtok(cmd, " \t");
  return (cmd);
}

int	locate_char(char *str, char chr)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == chr)
	return (i);
      i++;
    }
  return (0);
}

int	check_separator(char *cmd, char chr)
{
  int	i;

  i = locate_char(cmd, chr);
  if (cmd[i + 1] == chr)
    return (2);
  else if (i != 0)
    return (1);
  else
    return (-1);
}

int	check_cmd(char *cmd, t_vars *p)
{
  int	returned;
  char	*filename;

  returned = -1;
  filename = get_filename(strdup(cmd));
  p->filename_ok = check_filename(p, filename);
  if (p->filename_ok != -1)
    {
      if ((returned = check_separator(cmd, '>')) != -1)
	exec_redir_right(parse(cmd, ">"), returned, p);
      else if ((returned = check_separator(cmd, '<')) != -1)
	exec_redir_left(parse(cmd, "<"), returned, p);
      else if ((returned = check_separator(cmd, '&')) != -1)
	check_and(parse(cmd, "&"), returned, p);
      else if ((returned = check_separator(cmd, '|')) == 1)
	check_pipe(parse(cmd, "|"), returned, p);
      else
	exec_normal(cmd, p);
    }
  else
    {
      if ((returned = check_separator(cmd, '|')) == 2)
	check_pipe(parse(cmd, "|"), returned, p);
      else
	{
	  fprintf(stderr, "Command not found : %s\n", filename);
	  if (filename != NULL)
	    free(filename);
	  return (-1);
	}
    }
  if (filename != NULL)
    free(filename);
  return (0);
}
