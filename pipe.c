/*
** pipe.c for minishell2 in /home/isos/Workspace/Epitech/PSU_2016_minishell2
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Tue Dec  6 14:44:05 2016 Sébastien Jacobin
** Last update Sun Dec 25 22:29:55 2016 Sébastien Jacobin
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"

int	count_lim(char **cmd, char *lim)
{
  int	i;
  int	e;

  i = 0;
  e = 0;
  while (cmd && cmd[i] != NULL)
    if (my_strcmp(cmd[i++], lim) == 0)
      e = e + 1;
  return (e);
}

char	**get_cmd(char ***cmd, char *lim)
{
  int	i;
  char	**res;

  i = 0;
  if (cmd[0] != NULL)
    {
      res = malloc(sizeof(char*) * (my_ptrlen(cmd[0], lim) + 1));
      while (cmd[0][i] && my_strcmp(cmd[0][i], lim) != 0)
	{
	  res[i] = cmd[0][i];
	  i = i + 1;
	}
      res[i] = NULL;
      if (cmd[0][i] && my_strcmp(cmd[0][i], lim) == 0)
	cmd[0] = cmd[0] + i + 1;
      return (res);
    }
  return (NULL);
}
