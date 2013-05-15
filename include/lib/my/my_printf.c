/*
** my_printf.c for  in /home/fritsc_h//my_printf-2017-fritsc_h
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sun Nov 18 15:29:20 2012 harold fritsch
** Last update Sun May 12 20:00:06 2013 harold fritsch
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void	my_putstraff(char *str)
{
  int	i;

  i = 0;
  while (str && (str[i] != '\0'))
    {
      if ((str[i] < 32) || (str[i] >= 127))
	{
	  if (str[i] < 32)
	    my_putstr("\\0");
	  if (str[i] < 8)
	    my_putchar('0');
	  if (str[i] >= 127)
	    my_putstr("\\0");
	  my_put_nbrbase(str[i], "01234567");
	  i++;
	}
      else
	my_putchar(str[i++]);
    }
}

void	func_nonprinting(va_list ap, char *str, int i)
{
  if (str[i + 1] == 's')
    my_putstr(va_arg(ap, char *));
  if (str[i + 1] == 'S')
    my_putstraff(va_arg(ap, char *));
}

void	flags_sdicoux(va_list ap, char *str, int i)
{
  if ((str[i + 1] == 'd') || (str[i + 1] == 'i'))
    my_put_nbr(va_arg(ap, int));
  else if (str[i + 1] == 'c')
    my_putchar((char) va_arg(ap, int));
  else if (str[i + 1] == 'o')
    my_put_nbrbase(va_arg(ap, int), "01234567");
  else if (str[i + 1] == 'u')
    my_put_nbrbase(va_arg(ap, int), "0123456789");
  else if (str[i + 1] == 'x')
    my_put_nbrbase(va_arg(ap, int), "0123456789abcdef");
  else if (str[i + 1] == 'X')
    my_put_nbrbase(va_arg(ap, int), "0123456789ABCDEF");
  else if (str[i + 1] == '%')
    my_putchar('%');
  else if (str[i + 1] == 'b')
    my_put_nbrbase(va_arg(ap, int), "01");
  else if (str[i + 1] == 'p')
    {
      my_putstr("0x7FFF");
      my_put_nbrbase(va_arg(ap, int), "0123456789abcdef");
    }
  else if ((str[i + 1] == 'S') || (str[i + 1] == 's'))
    func_nonprinting(ap, str, i);
}

void	my_printf(char *str, ...)
{
  va_list	ap;
  int		i;
  int		a;

  i = 0;
  va_start(ap, str);
  while (str[i] != '\0')
    {
      a = 1;
      if (str[i] == '%')
	{
	  flags_sdicoux(ap, str, i);
	  i = i + 2;
	  a = -a;
	}
      if (a >= 0)
	my_putchar(str[i++]);
    }
  va_end(ap);
}
