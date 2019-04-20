/*
** access.c for minishell1 in /home/isos/Workspace/Epitech/PSU_2016_minishell1
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Tue Dec  6 11:37:59 2016 Sébastien Jacobin
** Last update Fri Dec  9 19:39:08 2016 Sébastien Jacobin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

char	*exec_file(char	*name, int *result)
{
  struct stat	sb;

  stat(name, &sb);
  if ((sb.st_mode & S_IFMT) == S_IFDIR)
    {
      *result = -1;
      return (NULL);
    }
  else if ((*result = access(name, F_OK)) >= 0)
    return (name);
  return (NULL);
}
