/*
** builtin.c for minishell2 in /home/isos/Workspace/Epitech/PSU_2016_minishell2
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sat Dec 17 17:48:49 2016 Sébastien Jacobin
** Last update Wed Dec 28 00:50:55 2016 Sébastien Jacobin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

builtin_t	new_built(char *name, builtin_fct builtin)
{
  builtin_t	new;

  new.name = name;
  new.builtin = builtin;
  return (new);
}

builtin_t	*init_builtins()
{
  builtin_t	*res;

  res = malloc(sizeof(builtin_t) * 6);
  res[0] = new_built("cd", (void (*)())chdir);
  res[1] = new_built("exit", exit);
  res[2] = new_built("env", my_env);
  res[3] = new_built("setenv", my_setenv);
  res[4] = new_built("unsetenv", my_unsetenv);
  res[5] = new_built("", NULL);
  return (res);
}

void	exec_builtin(char *cmd, char *arg, char ***envp, int *result)
{
  int	i;
  builtin_t	*builts;

  i = 0;
  *result = 0;
  builts = init_builtins();
  while (builts[i].builtin != NULL)
    {
      if (my_strcmp(cmd, builts[i].name) == 0 && my_strcmp(cmd, "env") == 0)
	builts[i].builtin(envp[0]);
      else if (my_strcmp(cmd, builts[i].name) == 0 &&
	       (my_strcmp(cmd, "setenv") == 0 || my_strcmp(cmd, "unsetenv") == 0))
	builts[i].builtin(arg, envp);
      else if (my_strcmp(cmd, builts[i].name) == 0
	       && my_strcmp(cmd, "exit") == 0)
	builts[i].builtin(0);
      else if (my_strcmp(cmd, builts[i].name) == 0)
	builts[i].builtin(arg);
      i = i + 1;
    }
}
