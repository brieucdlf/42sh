/*
** pipes.c for 42sh in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Sun May 12 16:56:01 2013 jean gravier
** Last update Mon May 13 19:24:47 2013 jean gravier
*/

#include "42.h"
#include "parse.h"
#include <unistd.h>

int	check_pipe(char **cmd_pipe, int number, t_vars *p)
{
  if (number == 1)
    exec_pipe(cmd_pipe, p);
  else if (number == 2)
    exec_or(cmd_pipe, p);
  else
    return (-1);
  return (0);
}

int	exec_pipe(char **cmd_pipe, t_vars *p)
{
  int	i;
  int	pipefd[2];
  pid_t	pid[2];

  i = 1;
  while (cmd_pipe[i] != NULL)
    {
      pid[0] = fork();
      if (pid[0] == 0)
	{
	  pipe(pipefd);
	  pid[1] = fork();
	  if (pid[1] > 0)
	    {
	      wait(NULL);
	      close(pipefd[1]);
	      dup2(pipefd[0], 0);
	      execute(cmd_pipe[i], p);
	    }
	  else if (pid[1] == 0)
	    {
	      close(pipefd[0]);
	      dup2(pipefd[1], 1);
	      execute(cmd_pipe[i - 1], p);
	    }
	  else
	    return (-1);
	  close(pipefd[0]);
	  close(pipefd[1]);
	}
      if (pid[0] > 0)
	{
	  wait(NULL);
	}
      else
	return (-1);
      i++;
    }
  return (0);
}

int	exec_or(char **cmd_or, t_vars *p)
{
  int	i;
  int	status;
  pid_t	pid[2];

  i = 1;
  while (cmd_or[i] != NULL)
    {
      pid[0] = fork();
      if (pid[0] > 0)
	wait(NULL);
      if (pid[0] == 0)
	{
	  if (p->filename_ok != -1)
	    {
	      pid[1] = fork();
	      if (pid[1] > 0)
		{
		  wait(&status);
		  if (status == 0)
		    execute(cmd_or[i], p);
		}
	      else if (pid[1] == 0)
		{
		  execute(cmd_or[i - 1], p);
		}
	      else
		return (-1);
	    }
	  else
	    execute(cmd_or[i], p);
	}
      else
	return (-1);
      i++;
    }
  return (0);
}
