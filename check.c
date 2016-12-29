/*
** check.c for minishell2 in /home/isos/Workspace/Epitech/PSU_2016_minishell2
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Wed Dec 28 00:41:06 2016 Sébastien Jacobin
** Last update Wed Dec 28 22:21:46 2016 Sébastien Jacobin
*/

#include <stdlib.h>
#include "my.h"

char	**check_cmd(char **s)
{
  int	i;

  i = 0;
  if (s)
    {
      if (my_strcmp(s[0], "|") == 0 ||  my_strcmp(s[0], ";") == 0)
	return (NULL);
      while (s[i])
	{
	  if (my_strcmp(s[i], "|") == 0 && s[i + 1] == NULL)
	    return (NULL);
	  if (s[i + 1] &&  my_strcmp(s[i], ";") == 0 && my_strcmp(s[i + 1], ";") == 0)
	    return (NULL);
	  i = i + 1;
	}
    }
  return (s);
}

int	check_builtin(char *cmd)
{
  int	i;
  builtin_t	*builts;

  i = 0;
  builts = init_builtins();
  while (builts[i].builtin != NULL)
    {
      if (my_strcmp(cmd, builts[i].name) == 0)
	return (1);
      i = i + 1;
    }
  return (0);
}

int	check_argenv(char *arg)
{
  int	i;
  int	e;

  i = 0;
  e = 0;
  while (arg[i])
    {
      if (arg[i] == '=')
	e = e + 1;
      i = i + 1;
    }
  if (e == 1)
    return (1);
  return (0);
}

int	check(char c, int  state)
{
  if (state)
    {
      if (c > ' ')
  	return (1);
    }
  else
    if (c > ' ' && c != '|' && c != ';')
      return (1);
  return (0);
}
