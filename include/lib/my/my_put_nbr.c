/*
** my_put_nbr.c for my_put_nbr in /home/gravie_j//piscine/lib
**
** Made by jean gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Wed Oct 10 11:40:40 2012 jean gravier
** Last update Wed May  1 14:10:36 2013 jean gravier
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 0 && nb < 10)
    {
      my_putchar(nb + '0');
    }
  else
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + '0');
    }
}
