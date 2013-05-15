/*
** main.c for 42sh in /home/fritsc_h//42sh
**
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Fri Apr 12 20:03:52 2013 harold fritsch
** Last update Mon May 13 19:14:48 2013 jean gravier
*/

#include "42.h"

void		init(t_vars *p)
{
  printf("\033[34m=====================\n\033[0m");
  printf("\033[34m|\033[0mBienvenue dans dish\033[34m|\033[0m\n");
  printf("\033[34m=====================\033[0m\n");
  signal(SIGINT, SIG_IGN);
  p->cur_cmd = 0;
  p->env_already_modified = 0;
  extract_path(p);
  p->filename_ok = 0;
}

char		**tab_dup(char **tab)
{
  int		i;
  int		len;
  char		**new_tab;

  if (tab != NULL)
    {
      len = tab_size(tab);
      if ((new_tab = malloc(sizeof(*new_tab) * (len + 1))) == NULL)
	return (NULL);
      i = -1;
      while (tab[++i])
	new_tab[i] = strdup(tab[i]);
      new_tab[i] = NULL;
      return (new_tab);
    }
  return (NULL);
}

/*
** cp env ds struct et appel de la boucle d'exec
*/

int		main(int ac, char **av, char **env)
{
  t_vars	p;

  (void)ac;
  (void)av;
  if ((p.list = malloc(sizeof(t_l_alias*))) == NULL)
    return (-1);
  p.env_is_set = 0;
  p.list = NULL;
  if (env != NULL)
    if (env[0] != NULL)
      p.env_is_set = 1;
  p.env = tab_dup(env);
  get_conf(&p);
  init(&p);
  shell_loop(&p);
  return (0);
}
