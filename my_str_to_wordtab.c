/*
** my_str_to_wordtab.c for Day08 in /home/jacobin_s/CPool_Day08/task04
** 
** Made by Sébastien Jacobin
** Login   <jacobin_s@epitech.net>
** 
** Started on  Thu Oct 13 09:30:59 2016 Sébastien Jacobin
** Last update Wed Dec 28 00:45:04 2016 Sébastien Jacobin
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	e;
  int	nb_word;
  char	**res;

  i = 0;
  e = 0;
  nb_word = nb_words(str);
  if ((res = malloc(sizeof(char *) * (nb_word + 1))) == NULL)
    return (NULL);
  while (str[e] != '\0')
    {
      if (check(str[e], 1))
	res[i] = insert_word(str, &e, &i);
      e = (str[e] != '\0' && str[e] <= ' ') ? e + 1 : e;
    }
  res[nb_word] = NULL;
  return (res);
}

int	nb_words(char *str)
{
  int	e;
  int	nb;

  e = 0;
  nb = 0;
  while (str && str[e] != '\0')
    {
      while (check(str[e], 1))
	{
	  if (str[e + 1] == '|' || str[e + 1] == ';'
	      || (e > 0 && str[e - 1] == '|' && str[e] > ' ')
	      || (e > 0 && str[e - 1] == ';' && str[e] > ' ')
	      || (!check(str[e + 1], 1)))
	    nb = nb + 1;
	  e = e + 1;
	}
      if (str[e] != '\0' && str[e] <= ' ')
	e = e + 1;
    }
  return (nb);
}

char	*insert_word(char *str, int *e, int *i)
{
  int	o;
  char	*res;

  o = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(&str[*e]) + 1))) == NULL)
    return (NULL);
  if (str[*e] == '|' || str[*e] == ';')
    {
      res[o] = str[*e];
      res[o + 1] = 0;
      *e = *e + 1;
    }
  else
    {
      while (check(str[*e], 0))
	{
	  res[o++] = str[*e];
	  *e = *e + 1;
	}
      res[o] = 0;
    }
  *i = *i + 1;
  return (res);
}
