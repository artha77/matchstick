/*
** tool.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Fri Feb 24 22:46:16 2017 dylan renard
** Last update Sat Feb 25 22:21:10 2017 dylan renard
*/

#include "matchstick.h"
#include <stdlib.h>

t_playable		*info_to_playable(int line, int match)
{
  t_playable		*elem;

  if ((elem = malloc(sizeof(t_playable))) == NULL)
    return (NULL);
  elem->line = line;
  elem->match = match;
  return (elem);
}

void			free_bin_map(char **bin_map)
{
  int			i;

  i = 0;
  while (bin_map[i] != NULL)
    {
      free(bin_map[i]);
      i++;
    }
}

void			my_free(int *map_copy, char **bin_map)
{
  free(map_copy);
  free_bin_map(bin_map);
}

t_info			*init_info(void)
{
  t_info		*info;

  if ((info = malloc(sizeof(t_info))) == NULL)
    return (NULL);
  info->best_nim_sum = NULL;
  info->i = 0;
  info->j = 0;
  return (info);
}

void			next(t_info *info)
{
  info->i++;
  info->j = 0;
}
