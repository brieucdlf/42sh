##
## Makefile for  in /home/fritsc_h//42sh
##
## Made by harold fritsch
## Login   <fritsc_h@epitech.net>
##
## Started on  Fri Apr 12 19:50:05 2013 harold fritsch
## Last update Mon May 13 20:04:02 2013 jean gravier
##

CC	=	gcc

RM	=	rm -f

MY1	=	include/

MY2	=	include/lib/my/

CFLAGS	+= 	-W -Wall -ansi -pedantic -g -Wextra -I$(MY1) -I$(MY2)

SRC	=	main.c \
		shell_loop/primaryloop.c \
		shell_loop/prompt.c \
		shell_loop/free.c \
		builtin/add_rem_show_env.c \
		builtin/env.c \
		builtin/echo.c \
		builtin/chdir.c \
		path/extract_path.c \
		parser/execute.c \
		parser/parse.c \
		parser/check_cmd.c \
		parser/check_builtin.c \
		parser/executions.c \
		parser/errors.c \
		parser/pipes.c \
		parser/and.c \
		cfg/parser.c \
		cfg/linked_list_functions.c \
		cfg/alias.c \
		cfg/set.c \
		alias/check_alias.c

LIB	=	include/lib

NAME	=	dish

OBJ	=	$(SRC:.c=.o)

$(NAME): 	$(OBJ)
	@echo "***********************LIB COMPIL**********************"
	make -C $(LIB)/my
	@echo "*********************END LIB COMPIL**********************"
	$(CC) $(OBJ) -o $(NAME) -L$(LIB) -lmy

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIB)/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB)/my/

re:	fclean all