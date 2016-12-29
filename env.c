/*
** env.c for minishell2 in /home/isos/Workspace/Epitech/PSU_2016_minishell2
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sat Dec 17 18:19:36 2016 Sébastien Jacobin
** Last update Thu Dec 29 01:37:51 2016 Sébastien Jacobin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_unsetenv(char *arg, char ***env)
{
  int	i;
  int	e;
  int	j;
  char	**res;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char*) * my_ptrlen(env[0]) + 1)) == NULL)
    return ((void)NULL);
  while (arg && env[0][j])
    {
      e = 0;
      if (my_strcmp(get_var_name(env[0][j], &e), arg) != 0)
	res[i++] = env[0][j];
      j = j + 1;
    }
  if (arg != NULL)
    {
      res[i] = NULL;
      env[0] = res;
    }
}

void	my_setenv(char *arg, char ***env)
{
  int	i;
  int	e;
  char	*new;

  i = 0;
  e = 0;
  if (arg)
    {
      if ((new = malloc(sizeof(char) * (my_strlen(arg) + 2))) == NULL)
	return ((void)NULL);
      while (arg[e])
	{
	  if (arg[e] != '$')
	    new[i++] = arg[e];
	  e = e + 1;
	}
      if (!check_argenv(arg))
	new[i++] = '=';
      new[i] = 0;
      i = 0;
      if ((get_var_env(env[0], get_var_name(new, &i))) == NULL)
	insert_var(new, env);
    }
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

char	*get_var_name(char *envp, int *i)
{
  char	*res;

  if ((res = malloc(sizeof(char) * (my_strlen_lim(envp, '=') + 1))) == NULL)
    return (NULL);
  while (envp[*i] != '=')
    {
      res[*i] = envp[*i];
      *i = *i + 1;
    }
  res[*i] = 0;
  *i = *i + 1;
  return (res);
}

void	insert_var(char *arg, char ***env)
{
  int	i;
  char **res;

  i = 0;
  if ((res = malloc(sizeof(char*) *(my_ptrlen(env[0]) + 2))) == NULL)
    return ((void)NULL);
  while (env[0][i])
    {
      res[i] = env[0][i];
      i = i + 1;
    }
  res[i] = arg;
  res[i + 1] = NULL;
  env[0] = res;
}
