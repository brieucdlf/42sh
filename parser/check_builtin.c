/*
** check_builtin.c for  in /home/fritsc_h//42sh-2017-fritsc_h
**
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  9 11:21:57 2013 harold fritsch
** Last update Mon May 13 21:53:55 2013 harold fritsch
*/

#include "42.h"

int	check_name(char *name, char **builtin_tab)
{
  int	i;

  i = -1;
  while (++i < 5)
    if (strcmp(name, builtin_tab[i]) == 0)
      return (i);
  return (-1);
}

char	**generate_builtin_tab(void)
{
  char	**tab;

  if ((tab = malloc(sizeof(*tab) * 6)) == NULL)
    return (NULL);
  tab[0] = strdup("cd");
  tab[1] = strdup("env");
  tab[2] = strdup("echo");
  tab[3] = strdup("setenv");
  tab[4] = strdup("unsetenv");
  tab[5] = NULL;
  return (tab);
}

void	call_echo(t_vars *p, int builtin_number, char **args, int size)
{
  int	i;

  i = 0;
  if (builtin_number == 2)
    {
      while (++i < size)
	{
	  echo(p, args[i]);
	  my_putchar(' ');
	}
    }
  my_putchar('\n');
}

void	call_func(t_vars *p, int builtin_number, char **args)
{
  int	size;

  size = tab_size(args);
  if (builtin_number == 0)
    if (size < 3)
      cd(args[1]);
    else
      fprintf(stderr, "cd : too many arguments\nUsage : cd [PATH]\n");
  else if (builtin_number == 1)
    my_env(p);
  else if (builtin_number == 3)
    if (size == 2)
      my_set_env(p, args[1]);
    else
      fprintf(stderr, "setenv : error\nUsage : setenv VAR=DATA\n");
  else if (builtin_number == 4)
    if (size == 2)
      rem_var(p, args[1]);
    else
      fprintf(stderr, "unsetenv : error\nUsage : unsetenv VAR[=DATA]\n");
  else
    call_echo(p, builtin_number, args, size);
}

int	check_builtin(t_vars *p, char **args)
{
  char	**builtin_tab;
  int	builtin_number;

  builtin_tab = generate_builtin_tab();
  if ((builtin_number = check_name(args[0], builtin_tab)) == -1)
    {
      free_tab(builtin_tab);
      return (-1);
    }
  call_func(p, builtin_number, args);
  free_tab(builtin_tab);
  return (0);
}
