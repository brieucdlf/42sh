/*
** get_next_line.c for  in /home/fritsc_h//progelem
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Mon Nov 19 14:19:17 2012 harold fritsch
** Last update Wed May  1 13:42:18 2013 harold fritsch
*/

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char		*mkstr(void)
{
  char		*str;

  if ((str = malloc(sizeof(str) * READ_SIZE + 1)) == NULL)
    return (NULL);
  return (str);
}

int		next_char(char *buff, int i)
{
  while (buff[i] == '\n' && buff[i + 1])
    i++;
  return (i);
}

int		str_cpy(char *buff, int i, int j, char *str)
{
  while ((buff[i] != '\n') && buff[i])
    str[j++] = buff[i++];
  str[j] = '\0';
  if (buff[i])
    i++;
  return (i);
}

char		*get_next_line(const int fd)
{
  static int	len = 0;
  static char	buff[READ_SIZE + 1];
  static int	i = 0;
  char		*str;
  int		j;

  j = 0;
  if (READ_SIZE < 0)
    return (NULL);
  if (i >= len)
    {
      if ((len = read(fd, buff, READ_SIZE)) == 0)
	return (NULL);
      buff[len] = '\0';
      i = 0;
    }
  if (len < 0)
    return (0);
  i = next_char(buff, i);
  if ((str = mkstr()) == NULL)
    return (NULL);
  i = str_cpy(buff, i, j, str);
  if (buff[i - 1] == '\0')
    return (NULL);
  return (str);
}
