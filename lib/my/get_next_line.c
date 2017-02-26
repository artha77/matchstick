/*
** get_next_line.c for get_next_line in /home/artha/CPE_2016_getnextline
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Thu Jan  5 13:26:49 2017 dylan renard
** Last update Sun Feb 26 21:23:59 2017 dylan renard
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

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

int			main_boucle_final(t_info1 info)
{
  while (info.i != info.ret)
    {
      if (info.buf[info.i] == '\n')
	info.status = 0;
      info.i++;
    }
  return (info.status);
}

t_return		*main_boucle(t_info1 info, char *rest, const int fd)
{
  t_return		*ret;

  info.i = 0;
  ret = malloc(sizeof(t_return));
  if ((info.ret = read(fd, &info.buf, READ_SIZE)) < 0) return (NULL);
  if (info.ret == 0 && rest == NULL) return (NULL);
  if (info.ret == 0 && rest != NULL)
    {
      ret->rest = rest;
      ret->status = info.status;
      return (ret);
    }
  info.buf[info.ret] = '\0';
  info.status = main_boucle_final(info);
  info.i = 0;
  rest = my_strcat(rest, info.buf);
  if (contain_0(rest) == 1)
    {
      ret->rest = rest;
      ret->status = info.status;
      return (ret);
    }
  ret->rest = rest;
  ret->status = info.status;
  return (ret);
}

t_return		*final(char *str, char *rest)
{
  t_return		*ret;

  str = cut(rest);
  ret = malloc(sizeof(t_return));
  if (str == NULL)
    {
      ret->str = my_strdup(str);
      ret->rest = my_strdup(str);
      return (ret);
    }
  if (str[0] == '\n' && count_n(rest) == 1)
    {
      ret->str = my_strdup("\n");
      ret->rest = NULL;
      return (ret);
      }
  if (my_strlen(str) == 1 && my_strcmp(str, "\n") == 0)
    rest = my_strdup(rest + 1);
  else
    rest = my_strdup(rest + (my_strlen(str) + 1));
  ret->str = my_strdup(str);
  ret->rest = my_strdup(rest);
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
	  if (ret == NULL || (RET == NULL)) RETURN;
	  rest = my_strdup(ret->rest);
	  info.status = ret->status;
	  if (contain_0(rest)) info.status = 0;
	}
    }
  if (contain_0(rest))
    {
      info.str = my_strdup(rest);
      rest = NULL;
      return (info.str);
    }
  ret = final(info.str, rest);
  rest = ret->rest;
  return (ret->str);
}
