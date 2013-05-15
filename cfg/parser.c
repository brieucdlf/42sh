/*
** parser.c for  in /home/fritsc_h//42sh-2017-fritsc_h/cfg
**
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  9 16:48:37 2013 harold fritsch
** Last update Mon May 13 20:39:46 2013 harold fritsch
*/

#include "42.h"

int	check_existing_conf_file(void)
{
  int	fd;

  if ((fd = open(CFG_FILENAME, O_RDONLY)) == -1)
    {
      fprintf(stderr, "Couldn't open %s\nTo generate one : ", CFG_FILENAME);
      fprintf(stderr, "'./dish -gencfg' or type gencfg in dish\n");
      return (-1);
    }
  return (fd);
}

char	**read_conf_file(void)
{
  int	fd;
  int	i;
  char	*buf;
  char	**file;

  if ((file = malloc(sizeof(*file) * BUF_SIZE)) == NULL)
    return (NULL);
  if ((fd = check_existing_conf_file()) == -1)
    return (NULL);
  i = 0;
  while ((buf = get_next_line(fd)) != NULL)
    if (buf[0] && (buf[0] != '#') && (buf[0] != '\n'))
      file[i++] = buf;
    else
      free(buf);
  file[i] = NULL;
  close(fd);
  return (file);
}

void	hash_tab(t_vars *p, char **file)
{
  int	i;

  i = 0;
  if (file)
    while (file[i])
      {
	if ((strncmp(file[i], "alias:", 6)) == 0)
	  separate(p, epur(epur(my_strdup(&file[i][6]), ' '), '\t'));
	else if ((strncmp(file[i], "set:", 4)) == 0)
	  set_it(p, epur(epur(my_strdup(&file[i][4]), ' '), '\t'));
	++i;
      }
}

int	get_conf(t_vars *p)
{
  char	**file;

  if ((file = read_conf_file()) == NULL)
    return (-1);
  hash_tab(p, file);
  free_tab(file);
  return (0);
}

int	generate_cfg(void)
{
  int	fd;
  int	size;

  if ((fd = open(CFG_FILENAME, O_CREAT | O_RDWR, 0644)) == -1)
    return (-1);
  if ((size = write(fd, "#This is a comment, it starts with # and end with" \
		   "\\n\n#You can put comment wherever you want.\n"\
		   "#Alias must be declared as :\nalias:toto='titi'"\
	    "\n\n#Set must be declared as :\nset:EDITOR='emacs'\n", 182)) == -1)
    return (-1);
  close(fd);
  return (0);
}
