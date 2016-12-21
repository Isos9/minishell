/*
** my_shell.c for minishell1 in /home/isos/Workspace/Epitech/PSU_2016_minishell1
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Tue Nov 22 14:13:08 2016 Sébastien Jacobin
** Last update Wed Dec 21 23:07:47 2016 Sébastien Jacobin
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

char	**check_cmd(char **s)
{
  int	i;

  i = 0;
  if (my_strcmp(s[0], "|") == 0)
    return (NULL);
  while (s[i])
    {
      if (my_strcmp(s[i], "|") == 0 && s[i + 1] == NULL)
	return (NULL);
      i = i + 1;
    }
  return (s);
}

void	exec_child(char **args, char **envp, int *result)
{
  int  fd[2 * count_pipe(args)];
  char	**cmd;
  char	*exec;
  int	nb_pipe;
  int	i;
  int	e;

  params_value(&i, &e, 0, 1);
  nb_pipe = count_pipe(args);
  make_pipes(fd, nb_pipe * 2);
  while (i <= nb_pipe)
    {
      cmd = get_cmd(&args);
      exec = get_path(*cmd, envp, result);
      if (*result == 0)
	if (fork() == 0)
	  {
	    my_fork(fd, i, e, nb_pipe);
	    close_all(fd, nb_pipe * 2);
	    execve(exec, cmd, envp);
	  }
      params_value(&i, &e, nb_pipe, 0);
    }
  close_all(fd, nb_pipe * 2);
  forks_waits(nb_pipe * 2);
}

int	exec_cmd(char *str, char ***envp)
{
  char	**args;
  int	result;

  args = my_str_to_wordtab(str);
  if (check_builtin(*args))
    {
      exec_builtin(*args, args[1], envp);
      result = 0;
    }  
  else
    {
      result = 0;
      if ((args = check_cmd(args)) == NULL)
	return ((result = -1));
      exec_child(args, envp[0], &result);
    }
  return (result);
}

int	main(int ac, char **av, char **envp)
{
  char	*s;

  signal(SIGINT, signal_cc);
  my_putstr(get_var_env(envp, "USER"));
  my_putstr(" & $> ");
  while ((s = get_next_line(0)))
    {
      if (my_strlen(s) > 0 && exec_cmd(s, &envp) < 0)
  	{
  	  my_putstr("command not found: ");
  	  my_putstr(s);
  	  my_putstr("\n");
  	}
      my_putstr(get_var_env(envp, "USER"));
      my_putstr(" & $> ");
    }
  return (0);
}
