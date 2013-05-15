/*
** check_alias.c for  in /home/fritsc_h//42sh-2017-fritsc_h/alias
** 
** Made by harold fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Mon May 13 13:54:55 2013 harold fritsch
** Last update Mon May 13 21:52:27 2013 harold fritsch
*/

#include "42.h"

char		*cut_first(char *cmd, int pos)
{
  char		*ret;

  if ((ret = malloc(sizeof(*ret) * (pos + 1))) == NULL)
    return (NULL);
  ret = strncpy(ret, cmd, pos);
  ret[pos] = '\0';
  return (ret);
}

char		*format_new_cmd(t_vars *p, char *cmd, int pos, int alias_len)
{
  char		*first_part;
  char		*second_part;
  char		*ret;
  int		final_len;

  first_part = cut_first(cmd, pos);
  second_part = my_strdup(&cmd[pos + alias_len]);
  final_len = strlen(first_part);
  final_len += strlen(second_part);
  final_len += strlen(p->tmp_data);
  if ((ret = malloc(sizeof(*ret) * (final_len + 1))) == NULL)
    return (NULL);
  sprintf(ret, "%s%s%s", first_part, p->tmp_data, second_part);
  p->end_alias_loop = 1;
  return (ret);
}

char		*check_alias(t_vars *p, char *cmd, char *alias, int alias_len)
{
  int		i;
  int		cmd_len;

  cmd_len = strlen(cmd);
  i = -1;
  if (strlen(cmd) >= (unsigned)alias_len)
    while ((unsigned)++i < (strlen(cmd) - ((unsigned)alias_len - 1)))
      if ((strncmp(&cmd[i], alias, alias_len) == 0) &&
	  ((cmd[i + alias_len] == '\0') || (cmd[i + alias_len] == ' ')
	   || (cmd[i + alias_len] == '\t') || (cmd[i + alias_len] == '|')
	   || (cmd[i + alias_len] == '&') || (cmd[i + alias_len] == ';')
	   || (cmd[i + alias_len] == '<') || (cmd[i + alias_len] == '>')))
	if (i > 0)
	  {
	    if ((cmd[i + alias_len - 1] == '\0') || (cmd[i - 1] == ' ')
		|| (cmd[i - 1] == '\t')	|| (cmd[i - 1] == '|')
		|| (cmd[i - 1] == '&') || (cmd[i - 1] == ';')
		|| (cmd[i - 1] == '<') || (cmd[i - 1] == '>'))
	      return (format_new_cmd(p, cmd, i, alias_len));
	  }
	else
	  return (format_new_cmd(p, cmd, i, alias_len));
  return (NULL);
}

char		*verify_alias(t_vars *p, char *cmd)
{
  t_l_alias	*tmp;
  char		*ret;

  tmp = p->list;
  p->end_alias_loop = 0;
  while (tmp && (p->end_alias_loop == 0))
    {
      p->tmp_data = tmp->data;
      ret = check_alias(p, cmd, tmp->alias, strlen(tmp->alias));
      if (ret != NULL)
	return (ret);
      tmp = tmp->next;
    }
}

char		*loop_alias(t_vars *p, char *cmd)
{
  static int	it = 0;
  char		*old_cmd;

  old_cmd = strdup("harodebo");
  while (cmd && (it < 1000))
    {
      old_cmd = cmd;
      cmd = verify_alias(p, cmd);
      ++it;
      if ((old_cmd != NULL) && (cmd == NULL))
	return (old_cmd);
    }
  if (it >= 1000)
    {
      fprintf(stderr, "Alias loop.");
      return (NULL);
    }
  return (NULL);
}
