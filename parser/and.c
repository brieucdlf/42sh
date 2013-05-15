/*
** and.c for 42sh in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Mon May 13 19:39:02 2013 jean gravier
** Last update Mon May 13 20:00:48 2013 jean gravier
*/

#include "parse.h"

int	check_and(char **cmd_and, int number, t_vars *p)
{
  if (number == 1)
    exec_and(cmd_and, p);
  else
    return (-1);
  return (0);
}

int	exec_and(char **cmd_and, t_vars *p)
{
  (void)cmd_and;
  (void)p;
}
