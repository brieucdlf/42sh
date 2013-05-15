/*
** my_strdup.c for  in /home/fritsc_h//42sh-2017-fritsc_h
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Mon May 13 10:05:42 2013 harold fritsch
** Last update Mon May 13 10:15:08 2013 harold fritsch
*/

#include <stdlib.h>

char	*my_strdup(char *str)
{
  int	len;
  char	*ret;
  int	i;

  len = 0;
  while (str[len])
    ++len;
  if ((ret = malloc(sizeof(*ret) * (len + 1))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    ret[i] = str[i];
  ret[i] = '\0';
  return (ret);
}
