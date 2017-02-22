/*
** gameplay.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Feb 21 13:35:30 2017 dylan renard
** Last update Wed Feb 22 16:33:55 2017 dylan renard
*/

#include "matchstick.h"
#include "gnl.h"

void		play(int line, int match, int *map)
{
  map[line - 1] -= match;
}

int		is_defeat(int *map)
{
  int		i;
  int		prev;

  i = 0;
  prev = map[i];
  while (prev == 0)
    {
      if ((prev = map[i]) == -1)
	return (1);
      i++;
    }
  return (-1);
}

int		turn_of_AI(int number_of_line, int max_num, int *map)
{
  return (random_ai(number_of_line, max_num, map));
}

int		turn_of_user(int number_of_line, int max_num, int *map)
{
  int		line;
  int		match;

  my_puts("\n\nYour turn:");
  match = -1;
  while (match == -1)
    {
      line = get_line("Line: ", number_of_line);
      match = get_match("Matches: ", line, max_num, map);
    }
  play(line, match, map);
  my_putstr(my_strcat("Player remove ", to_string(match)));
  my_puts(my_strcat(" match(es) from line ", to_string(line)));
  return (is_defeat(map));
}

int		start_game(int number_of_line, int max_num, int *map)
{
  int		defeat;

  defeat = -1;
  while (defeat <= 0)
    {
      display_game(number_of_line, map);
      if (defeat <= 0)
	defeat = turn_of_user(number_of_line, max_num, map);
      if  (defeat <= 0)
	defeat = turn_of_AI(number_of_line, max_num, map);
    }
  if (defeat == 1)
    {
      display_game(number_of_line, map);
      my_putstr("\nYou lost, to bad...");
      return (2);
    }
  else
    {
      display_game(number_of_line, map);
      my_putstr("\nI lost... snif... but I'll get you next time!!");
      return (1);
    }
}
