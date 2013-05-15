/*
** primaryloop.c for  in /home/fritsc_h//42sh/shell_loop
**
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Tue Apr 16 10:59:49 2013 harold fritsch
** Last update Mon May 13 21:54:24 2013 harold fritsch
*/

#include "42.h"
#include "../parser/parse.h"

char	*check_exit(t_vars *p)
{
  char	*tmp;

  (void)p;
  if ((tmp = get_next_line(0)) == NULL)
    return (NULL);
  else if (strcmp(tmp, "exit") == 0)
    {
      free(tmp);
      return (NULL);
    }
  else
    return (epur(epur(tmp, ' '), '\t'));
}

void	shell_loop(t_vars *p)
{
  char	*cmd;

  aff_prompt(p);
  while ((cmd = check_exit(p)) != NULL)
    {
      cmd = epur(epur(loop_alias(p, cmd), ' '), '\t');
      my_printf("%s\n", cmd);
      init_parser(cmd, p);
      aff_prompt(p);
      free(cmd);
    }
  free_memory(p);
}
