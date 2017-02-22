/*
** debug_display.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Wed Feb 22 16:22:17 2017 dylan renard
** Last update Wed Feb 22 16:32:42 2017 dylan renard
*/

#include "matchstick.h"
#include <stdlib.h>

void		display_bin_map_line(char *bin)
{
  int		i;

  i = 0;
  while (bin[i] != 2)
    {
      my_putchar(bin[i] + '0');
      i++;
    }
  my_putchar('\n');
}

void		display_bin_map(char **bin_map)
{
  int		i;

  i = 0;
  while (bin_map[i] != NULL)
    {
      display_bin_map_line(bin_map[i]);
      i++;
    }
}

void		display_pair_map_line(char *pair_line)
{
  int		i;

  i = 0;
  while (i != 8)
    {
      my_putstr(to_string((int)pair_line[i]));
      my_putchar(' ');
      i++;
    }
  my_putchar('\n');
}

void		display_pair_map(char **pair_map)
{
  int		i;

  i = 0;
  while (pair_map[i] != NULL)
    {
      display_pair_map_line(pair_map[i]);
      i++;
    }
}
