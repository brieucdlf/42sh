/*
** linked_list_functions.c for  in /home/fritsc_h//42sh-2017-fritsc_h
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sat May 11 17:02:33 2013 harold fritsch
** Last update Mon May 13 13:36:57 2013 harold fritsch
*/

#include "42.h"

t_l_alias	*add_to_list(t_l_alias *list, char *data, char *alias)
{
  t_l_alias	*new;

  if ((new = malloc(sizeof(t_l_alias))) == NULL)
    return ((t_l_alias*)NULL);  
  new->data = data;
  new->alias = alias;
  new->next = list;
  return (new);
}

void		free_list(t_l_alias *list)
{
  t_l_alias	*current;
  t_l_alias	*tmp;

  current = list;
  while (current)
    {
      free(current->data);
      free(current->alias);
      tmp = current;
      current = current->next;
      free(tmp);
    }
}

char		*find_in_list(t_l_alias *list, char *to_find)
{
  t_l_alias	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->next != NULL)
	{
	  if (tmp->alias && tmp->data)
	    if (strcmp(to_find, tmp->alias) == 0)
	      return (tmp->data);
	  tmp = tmp->next;
	}
      else
	tmp = NULL;
    }
  return (NULL);
}

void		show_list(t_l_alias *list)
{
  t_l_alias	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->alias && tmp->data)
	my_printf("alias : %s\ndata : %s\n", tmp->alias, tmp->data);
      tmp = tmp->next;
    }
}
