/*
** my_fork.c for minishell2 in /home/isos/Workspace/Epitech/PSU_2016_minishell2
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Fri Dec  9 17:25:19 2016 Sébastien Jacobin
** Last update Fri Dec  9 17:47:46 2016 Sébastien Jacobin
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

void	make_pipes(int *fd, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      pipe(fd + i);
      i = i + 2;
    }
}

void	forks_waits(int	nb)
{
  int	wait_var;
  int	i;

  i = 0;
  while (i < nb + 1)
    {
      wait(&wait_var);
      i = i + 1;
    }
}

void	close_all(int *fd, int nb)
{
  int	i;

  i = 0;
  while (i < nb + 1)
    close(fd[i++]);
}

void	my_fork(int *fd, int i, int e, int nb_pipe)
{
  if (i != 0)
    {
      dup2(fd[e - 1], 0);
      e = e + 2;
    }
  if (i != nb_pipe)
    dup2(fd[e], 1);
}

void	params_value(int *i, int *e, int nb_pipe, int state)
{
  if (state)
    {
      *i = 0;
      *e = 1;
    }
  else
    {
      *e = (*i != 0 && *i != nb_pipe) ? *e + 2 : *e;
      *i = *i + 1;
    }
}
