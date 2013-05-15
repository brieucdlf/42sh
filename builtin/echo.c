/*
** echo.c for  in /home/fritsc_h//42sh
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Tue Apr 30 15:10:23 2013 harold fritsch
** Last update Mon May 13 21:48:19 2013 harold fritsch
*/

#include "42.h"

char	*rem_return_line(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	str[i] = '\0';
      ++i;
    }
  return (str);
}

void	print_echo(t_vars *p, char *str)
{
  int	i;
  int	is_a_var;

  i = 0;
  is_a_var = 0;
  while ((str[i]) && (is_a_var == 0))
    {
      if (str[i] == '$')
	is_a_var = 1;
      ++i;
    }
  if (is_a_var == 0)
    my_printf("%s", rem_return_line(str));
  else
    if ((check_existing_variable(p, &str[1])) == 0)
      {
	i = 0;
	while ((str[i]) && (str[i] != '='))
	  ++i;
	my_printf("%s", &p->env[p->var_position + 1][i]);
      }
    else
      fprintf(stderr, "couldn't find any variable called %s\n", str);
}

int	count_word(char *str, char *sep)
{
  int	count_words;

  count_words = 1;
  strtok(strdup(str), sep);
  while (strtok(NULL, sep) != NULL)
    ++count_words;
  return (count_words);
}

void	*echo(t_vars *p, char *str)
{
  int	i;
  int	count_words;
  char	**tab;

  if (str[0] && (str[0] != '\n') && str)
    {
      count_words = count_word(str, " \t");
      if ((tab = malloc(sizeof(*tab) * (count_words + 1))) == NULL)
	return (NULL);
      tab[0] = strtok(str, " \t");
      i = 1;
      while (((tab[i] = strtok(NULL, " \t")) != NULL) && (i < count_words))
	++i;
      i = 0;
      while (i < count_words)
	{
	  print_echo(p, tab[i]);
	  ++i;
	  my_putchar(' ');
	}
    }
  return (NULL);
}
