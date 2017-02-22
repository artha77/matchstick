/*
** ai.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Wed Feb 22 08:08:02 2017 dylan renard
** Last update Wed Feb 22 16:31:26 2017 dylan renard
*/

#include "matchstick.h"
#include <stdlib.h>

int		smart_ai(int number_of_line, int max_num, int *map)
{
  char		**bin_map;
  char		**pair_map;

  bin_map = map_to_bin_map(number_of_line, map);
  display_bin_map(bin_map);
  my_putchar('\n');
  pair_map = bin_map_to_pair_map(number_of_line, bin_map);
  display_pair_map(pair_map);
  return (0);
}

int		random_ai(int number_of_line, int max_num, int *map)
{
  int		line;
  int		match;

  line = -1;
  match = -1;
  my_puts("\nAI's turn:");
  while (line == -1)
    {
      line = range_rand(1, number_of_line);
      if (line <= 0 || line > number_of_line)
	line = -1;
      else if (map[line - 1] == 0)
	line = -1;
    }
  while (match == -1)
    {
      match = range_rand(1, max_num);
      if (match <= 0 || match > map[line - 1])
	match = -1;
    }
  play(line, match, map);
  my_putstr(my_strcat("AI remove ", to_string(match)));
  my_puts(my_strcat(" match(es) from line ", to_string(line)));
  return (is_defeat(map) + 1);
}
