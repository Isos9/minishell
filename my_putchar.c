/*
** my_putchar.c for Day03 in /home/jacobin_s/CPool_Day03
** 
** Made by Sébastien Jacobin
** Login   <jacobin_s@epitech.net>
** 
** Started on  Wed Oct  5 10:17:14 2016 Sébastien Jacobin
** Last update Sun Dec  4 02:56:21 2016 Sébastien Jacobin
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
