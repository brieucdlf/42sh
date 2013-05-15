/*
** prompt.c for  in /home/fritsc_h//42sh/shell_loop
**
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Mon Apr 22 12:54:26 2013 harold fritsch
** Last update Mon May  6 14:49:31 2013 jean gravier
*/

#include "my.h"
#include "42.h"

char			*cut_this(char *str, int len)
{
  int			i;
  int			lenstr;
  char			*ret;

  i = 0;
  lenstr = strlen(str) - len;
  if ((ret = malloc(sizeof(ret) * lenstr)) == NULL)
    {
      fprintf(stderr, "error malloc ret\n");
      return (NULL);
    }
  while ((str[len]) && (str[len - 1] != '='))
    ++len;
  while (str[len])
    ret[i++] = str[len++];
  ret[i] = '\0';
  return (ret);
}

char			*check_var(char *var_name, t_vars *p)
{
  int			i;
  int			len;
  char			*ret;

  len = strlen(var_name) - 1;
  i = 0;
  if (p->env)
    while (p->env[i])
      {
	if ((strncmp(var_name, p->env[i], len)) == 0)
	  {
	    if ((ret = cut_this(p->env[i], len)) == NULL)
	      return (NULL);
	    return (ret);
	  }
	++i;
      }
  return (NULL);
}

char			*get_cur_dir()
{
  char			*cwd;

  if ((cwd = malloc(sizeof(cwd) * CWD_LEN)) == NULL)
    {
      fprintf(stderr, "error malloc cwd");
      return (NULL);
    }
  cwd = getcwd(cwd, CWD_LEN + 1);
  return (cwd);
}

void			aff_prompt(t_vars *p)
{
  char			*cwd;
  char			empty;

  empty = '\0';
  if ((p->username = check_var("USER", p)) == NULL)
    p->username = &empty;
  if ((p->hostname = check_var("HOST", p)) == NULL)
    p->hostname = &empty;
  my_printf("\033[2m%s\033[0m", p->username);
  my_printf("\033[2m%s\033[0m", p->hostname);
  my_printf("\033[33m•\033[0m\033[2m%d\033[0m\033[33m•\033[0m", p->cur_cmd++);
  my_printf("\033[32m%s\033[0m» ", cwd = get_cur_dir());
  free(cwd);
  if (p->username[0] != '\0')
    free(p->username);
  if (p->hostname[0] != '\0')
    free(p->hostname);
}
