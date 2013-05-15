/*
** my.h for  in /home/fritsc_h//42sh/include
**
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Fri Apr 12 20:13:40 2013 harold fritsch
** Last update Mon May 13 20:47:21 2013 harold fritsch
*/

#ifndef _42_H_

# define _42_H_
# define CWD_LEN (1024)
# define CFG_FILENAME ("./.cfg")
# define BUF_SIZE (1024)

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "my.h"

typedef	struct		s_vars
{
  int			cur_cmd;
  int			var_position;
  int			env_already_modified;
  int			path_nbr;
  int			env_is_set;
  int			filename_ok;
  char			*tmp_data;
  char			*buf_path;
  char			**path;
  char			*username;
  char			*hostname;
  char			**env;
  char			**alias;
  int			taille_env;
  int			end_alias_loop;
  struct s_l_alias	*list;
}			t_vars;

typedef struct		s_l_alias
{
  char			*alias;
  char			*data;
  struct s_l_alias	*next;
}			t_l_alias;

char	*get_next_line(int fd);
char	*epur(char *str, char sep);
char	*strdup(char *str);
char	*my_strdup(char *str);

/*
** path/extract_path.c
*/

int	ct_char(char *str, char character);
int	extract_path(t_vars *p);

/*
** builtin/chdir.c
*/

void	cd(char *path);

/*
** builtin/echo.c
*/

char	*rem_return_line(char *str);
void	print_echo(t_vars *p, char *str);
int	count_word(char *str, char *sep);
void	*echo(t_vars *p, char *str);

/*
** builtin/add_rem_show_env.c
*/

void	free_tab(char **tab);
int	add_var(t_vars *p, char *data);
int	my_set_env(t_vars *p, char *data);
char	**mk_new_env(t_vars *p, char **tmpenv);
int	rem_var(t_vars *p, char *data);

/*
** builtin/env.c
*/

void	my_env(t_vars *p);
int	tab_size(char **tab);
char	*correctdata(char *data);
int	check_existing_variable(t_vars *p, char *var_name);

/*
** shell_loop/free.c
*/

void	free_memory(t_vars *p);

/*
** shell_loop/primaryloop.c
*/

char	*check_exit(t_vars *p);
void	shell_loop(t_vars *p);

/*
** shell_loop/prompt.c
*/

char	*cut_this(char *str, int len);
char	*check_var(char *var_name, t_vars *p);
char	*get_cur_dir(void);
void	aff_prompt(t_vars *p);

/*
** cfg/parser.c
*/

int	check_existing_conf_file(void);
void	hash_tab(t_vars *p, char **file);
int	get_conf(t_vars *p);
int	generate_cfg(void);

/*
** cfg/linked_list_functions
*/

t_l_alias	*add_to_list(t_l_alias *list, char *data, char *alias);
void		free_list(t_l_alias *list);
void		show_list(t_l_alias *list);
char		*find_in_list(t_l_alias *list, char *to_find);

/*
** cfg/alias.c
*/

void		*separate(t_vars *p, char *str);
char		*get_alias(char *str, int alias_len);
void		free_alias(char *str, char *alias_buf, char *data_buf);

/*
** cfg/set.c
*/

char		*rem_char(char *str, char c);
void		set_it(t_vars *p, char *str);

/*
** alias/check_alias.c
*/

char		*cut_this_first(char *cmd, int start_pos);
char		*cut_this_then(char *cmd, int end_pos, int alias_len);
char		*check_alias_presence(char *cmd, char *alias);
char		*replace(t_vars *p, char *cmd);
char		*check_alias(t_vars *p, char *cmd, char *alias, int alias_len);

/*
** main.c
*/

char		**dup_env(char **env);
void		init(t_vars *p);
int		main(int ac, char **av, char **env);

#endif
