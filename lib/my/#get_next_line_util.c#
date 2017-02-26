/*
** get_next_line_util.c for lib in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Feb 26 20:01:46 2017 dylan renard
** Last update Sun Feb 26 20:03:04 2017 dylan renard
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int			count_n(char *str)
{
  int			i;
  int			count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	count++;
      i++;
    }
  return (count);
}

int			contain_0(char *rest)
{
  int			i;

  if (rest == NULL)
    return (1);
  i = 0;
  if (rest[i] == '\n')
    return (0);
  while (rest[i] != '\0')
    {
      i++;
      if (rest[i] == '\n')
	return (0);
    }
  return (1);
}

int			contain_n(char *rest)
{
  int			i;
  int			contain;

  i = 0;
  contain = 0;
  if (rest == NULL)
    return (0);
  if (rest[i] == '\n')
	contain++;
  while (rest[i] != '\n' && rest[i] != '\0')
    {
      i++;
      if (rest[i] == '\n')
	contain++;
    }
  return (contain);
}
