/*
** my_ptrlen.c for minishell in /home/isos/Workspace/Epitech/PSU_2016_minishell2
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Tue Dec  6 19:41:38 2016 Sébastien Jacobin
** Last update Wed Dec  7 15:37:16 2016 Sébastien Jacobin
*/

#include <unistd.h>
#include "my.h"

int	my_ptrlen(char	**cmd)
{
  int	i;

  i = 0;
  while (cmd[i] && (my_strcmp(cmd[i], "|") != 0))
    i = i + 1;
  return (i);
}
