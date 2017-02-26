/*
** get_next_line.c for get_next_line in /home/artha/CPE_2016_getnextline
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Thu Jan  5 13:26:49 2017 dylan renard
** Last update Sun Feb 26 16:59:41 2017 dylan renard
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

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

char			*cut(char *rest)
{
  int			i;
  char			*str;

  i = 0;
  while (rest[i] != '\n' && rest[i] != '\0')
    {
      i++;
    }
  if (rest[i] == '\0')
    return (NULL);
  if (i == 0)
    str = my_strdup("\n");
  else
    str = my_strndup(rest, i);
  return (str);
}

t_return		*main_boucle(t_info1 info, char *rest, const int fd)
{
  t_return		*ret;

  info.i = 0;
  ret = malloc(sizeof(t_return));
  if ((info.ret = read(fd, &info.buf, READ_SIZE)) < 0) return (NULL);
  if (info.ret == 0 && rest == NULL)
    return (NULL);
  if (info.ret == 0 && rest != NULL)
    return (NULL);
  info.buf[info.ret] = '\0';
  while (info.i != info.ret)
    {
      if (info.buf[info.i] == '\n')
	info.status = 0;
      info.i++;
    }
  info.i = 0;
  rest = my_strcat(rest, info.buf);
  ret->rest = rest;
  ret->status = info.status;
  return (ret);
}

char			*get_next_line(const int fd)
{
  static char		*rest = NULL;
  t_info1		info;
  t_return		*ret;

  info.status = 1;
  if (contain_n(rest) == 0)
    {
      while (info.status)
	{
	  ret = main_boucle(info, rest, fd);
	  if (ret == NULL) return (NULL);
	  rest = ret->rest;
	  info.status = ret->status;
	}
    }
  info.str = cut(rest);
  if (info.str == NULL)
    return (info.str);
  if (my_strlen(info.str) == 1 && my_strcmp(info.str, "\n") == 0)
    rest = my_strdup(rest + 1);
  else
    rest = my_strdup(rest + (my_strlen(info.str) + 1));
  return (info.str);
}
