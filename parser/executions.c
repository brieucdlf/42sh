/*
** redirections.c for 42sh in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Wed May  8 18:33:40 2013 jean gravier
** Last update Sun May 12 17:09:32 2013 jean gravier
*/

#include "parse.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	exec_redir_left_double(char *cmd, char *str, t_vars *p)
{
  char	*buffer;

  my_printf("?>");
  buffer = get_next_line(0);
  while (buffer != NULL && (strcmp(str, buffer) != 0))
    {
      if (buffer != NULL)
	free(buffer);
      my_printf("?>");
      buffer = get_next_line(0);
    }
  if (buffer != NULL)
    free(buffer);
  exec_normal(cmd, p);
  return (0);
}

int	exec_redir_left(char **cmd_redir, int number, t_vars *p)
{
  int	file_fd;
  pid_t	pid;
  int	i;

  i = 1;
  while (cmd_redir[i] != NULL)
    {
      if (number == 1)
	{
	  if ((file_fd = open(epur(strdup(cmd_redir[i]), ' '), O_RDONLY)) == -1)
	    {
	      open_error(epur(strdup(cmd_redir[i]), ' '));
	      return (-1);
	    }
	}
      else if (number == 2)
	return (exec_redir_left_double(cmd_redir[i - 1], epur(strdup(cmd_redir[i]), ' '), p));
      if ((pid = fork()) > 0)
	wait(NULL);
      else if (pid == 0)
	{
	  dup2(file_fd, 0);
	  execute(cmd_redir[i - 1], p);
	  close(file_fd);
	  return (0);
	}
      else
	return (-1);
      i++;
    }
  return (0);
}

int	exec_redir_right(char **cmd_redir, int number, t_vars *p)
{
  int	file_fd;
  pid_t	pid;
  int	i;

  i = 1;
  while (cmd_redir[i] != NULL)
    {
      if (number == 1)
	file_fd = open(epur(strdup(cmd_redir[i]), ' '), O_RDWR | O_CREAT | O_TRUNC, 0644);
      else if (number == 2)
	file_fd = open(epur(strdup(cmd_redir[i]), ' '), O_RDWR | O_CREAT | O_APPEND, 0644);
      if ((pid = fork()) > 0)
	{
	  wait(NULL);
	}
      else if (pid == 0)
	{
	  dup2(file_fd, 1);
	  execute(cmd_redir[i - 1], p);
	  close(file_fd);
	  return (0);
	}
      else
	return (-1);
      i++;
    }
  return (0);
}

int	exec_normal(char *cmd, t_vars *p)
{
  pid_t	pid;

  pid = fork();
  if (pid > 0)
    {
      wait(NULL);
      return (0);
    }
  else if (pid == 0)
    {
      execute(strdup(cmd), p);
      return (1);
    }
  else
    return (-1);
}
