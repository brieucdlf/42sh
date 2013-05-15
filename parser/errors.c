/*
** errors.c for 42sh in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Fri May 10 19:14:52 2013 jean gravier
** Last update Fri May 10 19:26:24 2013 jean gravier
*/

#include "parse.h"
#include "42.h"

void	open_error(char *filename)
{
  my_printf("Error while opening file named : %s\n", filename);
}
