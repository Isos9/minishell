/*
** path.c for minishell1 in /home/isos/Workspace/Epitech/PSU_2016_minishell1
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun Dec  4 03:17:52 2016 Sébastien Jacobin
** Last update Mon Dec 26 00:36:19 2016 Sébastien Jacobin
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*get_var_env(char **envp, char *env_var)
{
  int	i;
  int	e;
  char	*var;

  e = 0;
  if ((var = malloc(sizeof(char) * (my_strlen(env_var) + 1))) == NULL)
    return (NULL);
  while (*envp)
    {
      i = 0;
      while (i < my_strlen(env_var) && envp[0][i] != '=')
	  var[i] = envp[0][i++];
      var[i++] = '\0';
      if (my_strcmp(var, env_var) == 0)
	{
	  var = malloc(sizeof(char) * (my_strlen(envp[0]) + 1));
	  while (envp[0][i] != '\0')
	    var[e++] = envp[0][i++];
	  var[e] = '\0';
	  return (var);
	}
      envp = envp + 1;
    }
  return ("");
}

char	*get_path(char *cmd, char **envp, int *result)
{
  int	i;
  int	e;
  char	*var;
  char	*res;

  e = 0;
  *result = -1;
  if (cmd[0] == '.')
    return (exec_file(cmd, result));
  var = get_var_env(envp, "PATH");
  if ((res = malloc(sizeof(char) * (my_strlen(var) + 1))) == NULL)
    return (NULL);
  while (var && var[e] != '\0')
    {
      i = 0;
      while (var && var[e] != ':' && var[e] != '\0')
	res[i++] = var[e++];
      e = e + 1;
      res[i] = '\0';
      res = (res[i -1] != '/' && cmd[0] != '/') ? my_strcat(res, "/") : res;
      if (((*result = access(my_strcat(res, cmd), F_OK)) >= 0))
	return (my_strcat(res, cmd));
    }
  res = ((*result = access(cmd, F_OK)) >= 0) ? cmd : NULL;
  return (res);
}
