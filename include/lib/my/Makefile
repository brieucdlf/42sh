##
## Makefile for test in /home/fritsc_h//sandbox/piscine/makefile
##
## Made by harold fritsch
## Login   <fritsc_h@epitech.net>
##
## Started on  Mon Oct 22 10:56:10 2012 harold fritsch
## Last update Mon May 13 10:13:24 2013 harold fritsch
##

RENDU	=	../lib

CFLAGS	+=	-W -Wall -Werror -ansi -pedantic -Wextra

CC	=	gcc

RM	=	rm -f

MY	=	my.h

NAME	=	libmy.a

SRC	=	epur.c \
		my_strdup.c \
		my_putstr.c \
		my_put_nbr.c \
		my_put_nbr_base.c \
		get_next_line.c \
		my_printf.c \
		my_putchar.c \
		aff_tab.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ../$(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all