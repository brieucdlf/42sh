/*
** my.h for  in /home/fritsc_h//sandbox/my
**
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Fri Oct 12 14:27:53 2012 harold fritsch
** Last update Mon May 13 10:08:03 2013 harold fritsch
*/

#ifndef MY_H_

# define MY_H_
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int	my_putchar(char c);
char	*get_next_line(int fd);
void	my_put_nbr(int nb);
int	my_put_nbrbase(unsigned int nb, char *base);
int	my_putstr(char *str);
void	my_sort_int_tab(int *tab, int size);
void    my_printf(char *str, ...);
void	aff_tab(char **tab);
char	*my_strdup(char *str);

#endif
