/*
** chdir.c for  in /home/fritsc_h//42sh/builtin
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Mon Apr 22 13:04:51 2013 harold fritsch
** Last update Thu May  9 14:17:23 2013 harold fritsch
*/

#include "42.h"

void	cd(char *path)
{
  if (path != NULL)
    if (chdir(path) == -1)
      fprintf(stderr, "Error, couldn't access to %s\n", path);
}
