/*
** env.c for minishell2 in /home/isos/Workspace/Epitech/PSU_2016_minishell2
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sat Dec 17 18:19:36 2016 Sébastien Jacobin
** Last update Sun Dec 25 23:52:17 2016 Sébastien Jacobin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_unsetenv(char *arg, char ***env)
{
  int	i;
  int	e;
  int	j;
  char	*var;
  char	**res;

  i = 0;
  j = 0;
  var = malloc(sizeof(char) * (my_strlen(arg) + 1));
  res = malloc(sizeof(char*) * my_ptrlen(env[0]) + 1);
  while (env[0][j])
    {
      e = 0;
      while (e < my_strlen(arg))
	var[e] = env[0][j][e++];
      var[e] = '\0';
      if (my_strcmp(var, arg) != 0)
	{
	  res[i] = env[0][j];
	  i = i + 1;
	}
      j = j + 1;
    }
  res[i] = NULL;
  env[0] = res;
}

void	my_setenv(char *arg, char ***env)
{
  int	i;
  char	**res;

  i = 0;
  res = malloc(sizeof(char*) *(my_ptrlen(env[0]) + 2));
  while (env[0][i])
    {
      res[i] = env[0][i];
      i = i + 1;
    }
  res[i] = arg;
  res[i + 1] = NULL;
  env[0] = res;
}

void	my_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      my_putstr(env[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

int	check_argenv(char *arg)
{
  int	i;

  i = 0;
  while (arg[i] != '=')
    {
      if (arg[i] <= 'A' && arg[i] >= 'Z' && arg[i] != '_')
	return (0);
      i = i + 1;
    }
  return (1);
}
