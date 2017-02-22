/*
** special_map.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Wed Feb 22 16:27:05 2017 dylan renard
** Last update Wed Feb 22 16:28:29 2017 dylan renard
*/

#include "matchstick.h"
#include <stdlib.h>

int		*dup_map(int number_of_line, int *map)
{
   int		*map_copy;
   int		i;

   i = 0;
  if ((map = malloc((number_of_line + 1) * sizeof(int))) == NULL)
    return (NULL);
  while (map[i] != -1)
    {
      map_copy[i] = map[i];
      i++;
    }
  map_copy[number_of_line] = -1;
  return (map_copy);
}

char		*char_to_bit(int c)
{
  char		*bit;
  int		len;
  int		i;

  bit = malloc(9 * sizeof(char));
  len = 7;
  i = len;
  while (i >= 0)
    {
      bit[len - i] = (c >> i) & 1;
      i--;
    }
  bit[len + 1] = 2;
  return (bit);
}

char		**map_to_bin_map(int number_of_line, int *map)
{
  char		**bin_map;
  int		i;

  i = 0;
  if ((bin_map = malloc((number_of_line + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (map[i] != -1)
    {
      bin_map[i] = char_to_bit(map[i]);
      i++;
    }
  bin_map[i] = NULL;
  return (bin_map);
}

char		*bin_line_to_pair_line(char *bin_line)
{
  char		*pair_line;
  int		i;
  int		increment;

  i = 7;
  increment = 1;
  if ((pair_line = malloc(8 * sizeof(char))) == NULL)
    return (NULL);
  while (i != -1)
    {
      if (bin_line[i] == 1)
	pair_line[i] = increment;
      else
	pair_line[i] = 0;
      i--;
      increment *= 2;
    }
  return (pair_line);
}

char		**bin_map_to_pair_map(int number_of_line, char **bin_map)
{
  char		**pair_map;
  int		i;

  i = 0;
  if ((pair_map = malloc((number_of_line - 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (bin_map[i] != NULL)
    {
      pair_map[i] = bin_line_to_pair_line(bin_map[i]);
      i++;
    }
  pair_map[i] = NULL;
  return (pair_map);
}
