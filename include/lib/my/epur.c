/*
** epur.c for  in /home/fritsc_h//42sh/include/lib/my
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Tue Apr 23 11:46:08 2013 harold fritsch
** Last update Wed May  1 13:41:44 2013 harold fritsch
*/

#include "my.h"

char	*epur(char *str, char sep)
{
  int	a;
  int	i;
  char	*buffer;

  i = 0;
  a = 0;
  if ((str != NULL) && (str[0] == '\0'))
    return (str);
  if ((buffer = malloc(sizeof(buffer) * strlen(str))) == NULL)
    return (NULL);
  while (str[a] == sep)
    a++;
  while (str[a] != '\0')
    if ((str[a] == sep) && (str[a + 1] == sep))
      a++;
    else
      buffer[i++] = str[a++];
  while (buffer[i - 1] == sep)
    i--;
  buffer[i] = '\0';
  free(str);
  return (buffer);
}
