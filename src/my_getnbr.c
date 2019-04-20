/*
** my_getnbr.c for my_getnbr.c in /home/jacobin_s/lib
** 
** Made by Sébastien Jacobin
** Login   <jacobin_s@epitech.net>
** 
** Started on  Tue Oct 11 14:50:59 2016 Sébastien Jacobin
** Last update Thu Dec 29 22:51:56 2016 Sébastien Jacobin
*/

#include "my.h"

int	check_neg_str(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	  return (1);
      i = i + 1;
    }
  return (0);
}

int	convertnbr(char *str)
{
  int	num;
  int	i;
  int	stop;
  int	digits;

  i = 0;
  num = 0;
  digits = 0;
  stop = 0;
  while (str[i] != '\0' && stop != 1)
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  digits = digits + 1;
	  if (digits > 10)
	    return (0);
	  if (str[i + 1] < '0' || str[i + 1] > '9')
	    stop = 1;
	  num = num + str[i] - 48;
	  if (stop != 1)
	      num = num * 10;
	}
      i = i + 1;
    }
  return (num);
}

int	my_getnbr(char  *str)
{
  int	num;
  int	neg;
  int	i;

  i = 0;
  neg = check_neg_str(str);
  num = convertnbr(str);
  if (neg == 1)
    num = num * -1;
  return (num);
}
