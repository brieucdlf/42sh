/*
** free.c for  in /home/fritsc_h//42sh
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Wed Apr 17 17:52:42 2013 harold fritsch
** Last update Sun May 12 16:59:30 2013 harold fritsch
*/

#include "42.h"

void	free_memory(t_vars *p)
{
  free_list(p->list);
  if (p->env_is_set == 1)
    {
      free_tab(p->env);
      free(p->path);
      free(p->buf_path);
    }
}
