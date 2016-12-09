/*
** my_strcmp.c for my_strcmp.c in /home/jacobin_s/CPool_Day06
** 
** Made by Sébastien Jacobin
** Login   <jacobin_s@epitech.net>
** 
** Started on  Mon Oct 10 11:49:52 2016 Sébastien Jacobin
** Last update Wed Dec  7 15:46:51 2016 Sébastien Jacobin
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
      i = i + 1;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  return (s1[i] - s2[i]);
}
