/*
** my_putchar.c for my_putchar in /home/fritsc_h//sandbox
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Wed Oct  3 15:11:55 2012 harold fritsch
** Last update Wed May  1 13:43:39 2013 harold fritsch
*/

#include "my.h"

int	my_putchar(char character)
{
  if ((write(1, &character, 1) == -1))
    return (-1);
  return (0);
}
