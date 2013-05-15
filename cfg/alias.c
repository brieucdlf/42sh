/*
** alias.c for  in /home/fritsc_h//42sh-2017-fritsc_h
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sun May 12 18:11:34 2013 harold fritsch
** Last update Mon May 13 13:29:14 2013 harold fritsch
*/

#include "42.h"

char	*get_alias(char *str, int alias_len)
{
  char	*alias_buf;
  int	i;

  if ((alias_buf = malloc(sizeof(*alias_buf) * (alias_len + 1))) == NULL)
    return (NULL);
  alias_buf = strncpy(alias_buf, str, alias_len);
  i = -1;
  while (++i < alias_len)
    alias_buf[i] = str[i];
  alias_buf[i] = '\0';
  return (alias_buf);
}

void	free_alias(char *str, char *alias_buf, char *data_buf)
{
  free(str);
  free(alias_buf);
  free(data_buf);
}

void    *separate(t_vars *p, char *str)
{
  int   i;
  int   alias_len;
  char  *alias_buf;
  char  *data_buf;
  int   data_len;
  int   data_pos;

  i = -1;
  alias_len = 0;
  while (str && str[++i] && (str[i] != '='))
    ++alias_len;
  alias_buf = get_alias(str, alias_len);
  data_len = 0;
  while (str && str[i] && str[i] != 39)
    data_pos = (++i + 1);
  while (str && str[i] && str[++i] != 39)
    ++data_len;
  if ((data_buf = malloc(sizeof(*data_buf) * (data_len + 2))) == NULL)
    return (NULL);
  data_buf = strncpy(data_buf, &str[data_pos], data_len);
  data_buf[data_len] = '\0';
  p->list = add_to_list(p->list, strdup(data_buf), strdup(alias_buf));
  free_alias(str, alias_buf, data_buf);
  return (NULL);
}
