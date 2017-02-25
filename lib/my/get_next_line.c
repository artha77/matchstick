/*
** get_next_line.c for get_next_line in /home/artha/CPE_2016_getnextline
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Thu Jan  5 13:26:49 2017 dylan renard
** Last update Sat Feb 25 16:40:39 2017 dylan renard
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

static int		my__strlen(char *str)
{
  int			i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

static char		*my_realloc_cpy(char *base, char *to_add)
{
  char			*final;
  int			i;
  int			j;
  int			len_base;
  int			len_add;

  i = -1;
  j = -1;
  len_base = my__strlen(base);
  len_add = my__strlen(to_add);
  if ((final = malloc(len_base + len_add + 1)) == NULL)
    return (NULL);
  while (j != (len_base - 1))
    final[++i] = base[++j];
  j = -1;
  while (j != (len_add - 1))
    final[++i] = to_add[++j];
  final[i + 1] = '\0';
  return (final);
}

static t_stat		*init_static(t_stat *statique, int fd)
{
  if ((statique = malloc(sizeof(t_stat))) == NULL)
    return (NULL);
  statique->fd = fd;
  statique->rest = NULL;
  statique->ret = 0;
  return (statique);
}

static char		*n_to_zero(t_stat *statique)
{
  char			*final;
  char			*pt;
  int			i;

  i = 0;
  if (statique->rest == NULL)
    return (NULL);
  if ((final = malloc(my__strlen(statique->rest) + 1)) == NULL)
    return (NULL);
  while (statique->rest[i] != '\n' && statique->rest[i] != '\0')
    {
      final[i] = statique->rest[i];
      i++;
    }
  if (statique->rest[i] == '\0')
    return (NULL);
  final[i] = '\0';
  pt = statique->rest;
  if ((statique->rest = my_realloc_cpy((statique->rest + i + 1), NULL)) == NULL)
    return (NULL);
  free(pt);
  return (final);
}

char			*get_next_line(const int fd)
{
  int			statut;
  int			i;
  char			buf[READ_SIZE + 1];
  char			*final;
  static t_stat		*statique = NULL;

  i = 0;
  statut = 1;
  statique = (statique == NULL || FD) ? init_static(statique, fd) : statique;
  if ((final = n_to_zero(statique)) != NULL) return (final);
  while (statut)
    {
      if ((statique->ret = read(fd, &buf, READ_SIZE)) <= 0) return (NULL);
      buf[statique->ret] = '\0';
      while ((i != (statique->ret) && statut != 0))
	{
	  if (buf[i] == '\n')
	    statut = 0;
	  i++;
	}
      statique->rest = my_realloc_cpy(statique->rest , buf);
      i = 0;
    }
  if ((final = n_to_zero(statique)) == NULL) return (NULL);
  return (final);
}
