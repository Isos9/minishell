/*
** my_shell.c for minishell1 in /home/isos/Workspace/Epitech/PSU_2016_minishell1
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Tue Nov 22 14:13:08 2016 Sébastien Jacobin
** Last update Fri Dec  9 17:44:04 2016 Sébastien Jacobin
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

int	exec_cmd(char *str, char **envp)
{
  char	**args;
  pid_t	pid;
  int	result;

  args = my_str_to_wordtab(str);
  if (my_strcmp(*args, "cd") == 0)
    result = chdir(args[1]);
  else if (my_strcmp(*args, "exit") == 0)
    exit(0);
  else
    {
      exec_child(args, envp, &result);
    }
  return (result);
}

int	main(int ac, char **av, char **envp)
{
  char	*s;

  signal(SIGINT, signal_cc);
  my_putstr("$> ");
  while ((s = get_next_line(0)))
    {
      if (my_strlen(s) > 0 && exec_cmd(s, envp) < 0)
  	{
  	  my_putstr("command not found: ");
  	  my_putstr(s);
  	  my_putstr("\n");
  	}
      my_putstr("$> ");
    }
  return (0);
}
