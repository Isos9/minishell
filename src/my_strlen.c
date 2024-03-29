/*
** my_strlen.c for Day04 in /home/jacobin_s/CPool_Day04
** 
** Made by Sébastien Jacobin
** Login   <jacobin_s@epitech.net>
** 
** Started on  Thu Oct  6 20:57:59 2016 Sébastien Jacobin
** Last update Wed Dec 28 22:20:54 2016 Sébastien Jacobin
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    i = i + 1;
  return (i);
}

int	my_strlen_lim(char *str, char lim)
{
  int	i;

  i = 0;
  while (str && str[i] != lim)
    i = i + 1;
  return (i);
}
