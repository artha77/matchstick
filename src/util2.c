/*
** util2.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sat Feb 25 16:36:41 2017 dylan renard
** Last update Sat Feb 25 16:55:07 2017 dylan renard
*/

#include "matchstick.h"

void		state1(int *map, int number_of_line)
{
  int		line;

  line = find_line(map, number_of_line);
  if (is_pair(map, number_of_line) == 0)
    {
      print_msg(line, map[line]);
      play(line + 1, map[line], map);
    }
  else
    {
      print_msg(line, map[line] -1);
      play(line + 1, map[line] - 1, map);
    }
}

int		find_line(int *map, int number_of_line)
{
  int		i;

  i = 0;
  while (i != number_of_line)
    {
      if (map[i] > 1)
	return (i);
      i++;
    }
}

int		is_pair(int *map, int number_of_line)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (i != number_of_line)
    {
      if (map[i] == 1)
	count++;
      i++;
    }
  if ((count % 2) == 0)
    return (1);
  else
    return (0);
}

int		find_first_line(int *map, int number_of_line)
{
  int		i;

  i = 0;
  while (i != number_of_line)
    {
      if (map[i] == 1)
	return (i);
      i++;
    }
}

void		print_msg(int line, int match)
{
  my_putstr(my_strcat("AI removed ", to_string(match)));
  my_puts(my_strcat(" match(es) from line ", to_string(line + 1)));
}
