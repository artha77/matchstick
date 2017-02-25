/*
** ai_util.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Fri Feb 24 22:50:24 2017 dylan renard
** Last update Fri Feb 24 22:52:33 2017 dylan renard
*/

#include "matchstick.h"
#include <stdlib.h>

void		display_nim_sum(char *nim_sum)
{
  int		i;

  i = 0;
  while (nim_sum[i] != 2)
    {
      my_putchar(nim_sum[i] + '0');
      my_putchar(' ');
      i++;
    }
  my_putchar('\n');
}

char		compute_nim_row(char **bin_map, int row)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (bin_map[i] != NULL)
    {
      if (bin_map[i][row] == 1)
	  count++;
      i++;
    }
  if (count == 0)
    count = 2;
  return ((count % 2 == 1) ? 1 : 0);
}

char		*compute_nim_sum(char **bin_map)
{
  char		*nim_sum;
  int		i;
  int		j;

  if ((nim_sum = malloc(9 * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (i != 8)
    {
      nim_sum[i] = compute_nim_row(bin_map, i);
      i++;
    }
  nim_sum[i] = 2;
  return (nim_sum);
}

int		nim_sum_equal_zero(char *nim_sum)
{
  int		i;

  i = 0;
  while (nim_sum[i] != 2)
    {
      if (nim_sum[i] == 1)
	return (0);
      i++;
    }
  return (1);
}

bool			is_best_nim_sum(char *current, char *best)
{
  int			i;
  int			num_current;
  int			num_best;

  if (best == NULL)
    return (true);
  i = 0;
  num_current = 0;
  num_best = 0;
  while (i != 8)
    {
      if (best[i] == 1)
	num_best++;
      if (current[i] == 1)
	num_current++;
      i++;
    }
  if (num_current >= num_best)
    return (false);
  return (true);
}
