/*
** my_putstr.c for Day04 in /home/jacobin_s/CPool_Day04
** 
** Made by Sébastien Jacobin
** Login   <jacobin_s@epitech.net>
** 
** Started on  Thu Oct  6 20:18:35 2016 Sébastien Jacobin
** Last update Sun Dec  4 02:54:03 2016 Sébastien Jacobin
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
