/*
** map.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Feb 21 13:28:55 2017 dylan renard
** Last update Tue Feb 21 15:42:48 2017 dylan renard
*/

#include <stdlib.h>
#include "matchstick.h"

int		*map_generator(int number_of_line)
{
  int		*matchstick_map;
  int		i;
  int		nb_stick;

  i = 0;
  nb_stick = 1;
  if ((matchstick_map = malloc((number_of_line + 1) * sizeof(int))) == NULL)
      return (NULL);
  while (i != (number_of_line))
    {
      matchstick_map[i] = nb_stick;
      nb_stick += 2;
      i++;
    }
  matchstick_map[number_of_line] = -1;
  return (matchstick_map);
}

void		display_game(int number_of_line, int *map)
{
  int		max_stick;
  int		i;
  int		space;

  max_stick = (number_of_line * 2) - 1;
  i = 0;
  space = ((max_stick + 1) / 2) -1;
  my_putstr_n_time("*", (max_stick + 2));
  while (map[i] != -1)
    {
      my_putstr("\n*");
      my_putstr_n_time(" ", space);
      my_putstr_n_time("|", map[i]);
      my_putstr_n_time(" ", space + ((((i + 1) * 2) - 1) - map[i]));
      my_putstr("*");
      i++;
      space -= 1;
    }
  my_putchar('\n');
  my_putstr_n_time("*", (max_stick + 2));
}
