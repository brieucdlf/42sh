/*
** parse.h for 42sh in /home/graviej/Projets/42sh-2017-fritsc_h
**
** Made by jean gravier
** Login   <graviej@epitech.net>
**
** Started on  Wed May  8 17:56:47 2013 jean gravier
** Last update Mon May 13 20:01:22 2013 jean gravier
*/

#ifndef PARSE_H_
# define PARSE_H_

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "42.h"

void	init_parser(char *cmd, t_vars *p);
int	get_size(char *str, char *delim);
char	**parse(char *cmd, char *delim);

char	*strdup(char *);

char	*get_path(t_vars *p, char *filename);
char	*make_path(char *env_path, char *filename);
char	*get_filename(char *cmd);

void	execute(char *cmd, t_vars *p);
int	exec_redir_left(char **cmd_redir, int number, t_vars *p);
int	exec_redir_left_double(char *cmd, char *str, t_vars *p);
int	exec_redir_right(char **cmd_redir, int number, t_vars *p);
int	exec_normal(char *cmd, t_vars *p);
int	exec_pipe(char **cmd_pipe, t_vars *p);
int	exec_or(char **cmd_or, t_vars *p);
int	exec_and(char **cmd_and, t_vars *p);

int	check_separator(char *cmd, char chr);
int	check_cmd(char *cmd, t_vars *p);
int	check_filename(t_vars *p, char *filename);
int	check_pipe(char **cmd_pipe, int number, t_vars *p);
int	check_and(char **cmd_and, int number, t_vars *p);
int	locate_char(char *str, char chr);

void	open_error(char *filename);

/*
** check_builtin.c
*/

int	check_name(char *name, char **builtin_tab);
char	**generate_builtin_tab(void);
void	call_echo(t_vars *p, int builtin_number, char **args, int size);
void    call_func(t_vars *p, int builtin_number, char **args);
int     check_builtin(t_vars *p, char **args);

#endif /* PARSE_H */
