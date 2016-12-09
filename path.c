/*
** path.c for minishell1 in /home/isos/Workspace/Epitech/PSU_2016_minishell1
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun Dec  4 03:17:52 2016 Sébastien Jacobin
** Last update Fri Dec  9 19:56:44 2016 Sébastien Jacobin
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*get_var_path(char **envp)
{
  int	i;
  int	e;
  int	j;
  char	*var;

  e = 0;
  j = 0;
  var = malloc(sizeof(char) * 6);
  while (*envp != NULL)
    {
      i = 0;
      while (i < 5 && envp[j][i] != '=')
	  var[i] = envp[j][i++];
      var[i++] = '\0';
      if (my_strcmp(var, "PATH") == 0)
	{
	  var = malloc(sizeof(char) * (my_strlen(envp[j]) + 1));
	  while (envp[j][i] != '\0')
	    var[e++] = envp[j][i++];
	  var[e] = '\0';
	  return (var);
	}
      j = j + 1;
    }
  return (NULL);
}

char	*get_path(char *cmd, char **envp, int *result)
{
  int	i;
  int	e;
  char	*var;
  char	*res;

  e = 0;
  *result = 0;
  if (cmd[0] == '.')
    return (exec_file(cmd, result));
  var = get_var_path(envp);
  res = malloc(sizeof(char) * (my_strlen(var) + 1));
  while (var[e] != '\0')
    {
      i = 0;
      while (var[e] != ':' && var[e] != '\0')
	res[i++] = var[e++];
      e = e + 1;
      res[i] = '\0';
      res = my_strcat(res, "/");
      if ((*result = access(my_strcat(res, cmd), F_OK)) >= 0)
	return (my_strcat(res, cmd));
    }
  return (NULL);
}
