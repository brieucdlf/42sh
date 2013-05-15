/*
** my_put_nbr_base.c for  in /u/all/fritsc_h/rendu/lib/my
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sun Nov 18 18:45:13 2012 harold fritsch
** Last update Tue Apr 23 11:44:10 2013 harold fritsch
*/

#include "my.h"

int     my_put_nbrbase(unsigned int nbr, char *base)
{
  int   base_len;

  base_len = strlen(base);
  if (nbr == 0)
    return (nbr);
  else
    my_put_nbrbase((nbr / base_len), base);
  my_putchar(base[nbr % base_len]);
  return (nbr);
}
