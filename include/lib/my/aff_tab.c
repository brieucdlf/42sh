/*
** aff_tab.c for aff_tab in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Sat May 11 18:23:19 2013 jean gravier
** Last update Sat May 11 18:32:22 2013 jean gravier
*/

#include <stdlib.h>
#include "my.h"

void	aff_tab(char **tab)
{
  int	i;

  while (tab[i] != NULL)
    {
      my_printf("%s$\n", tab[i]);
      i++;
    }
}
