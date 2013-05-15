/*
** my_putstr.c for  in /home/fritsc_h//sandbox/putstr
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Fri Oct  5 09:35:34 2012 harold fritsch
** Last update Sun May 12 17:02:59 2013 harold fritsch
*/

#include "my.h"

int	my_putstr(char *str)
{
  if (str)
    if ((write(1, str, strlen(str))) == -1)
      return (-1);
  return (0);
}
