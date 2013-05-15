/*
** xfree.c for xfree in /home/delafob/delafo_b/SVN/42sh-2017-fritsc_h
** 
** Made by Brieuc de La Fouchardière
** Login   <delafob@epitech.net>
** 
** Started on  Mon May 13 21:24:36 2013 Brieuc de La Fouchardière
** Last update Tue May 14 19:08:54 2013 Brieuc de La Fouchardière
*/

#include "42sh"

/*
** Free ptr & get ptr == NULL
*/

void	xfree(void *ptr)
{
  free(ptr);
  if (ptr != NULL)
    ptr = NULL;
  return ;
}
