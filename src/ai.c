/*
** ai.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Wed Feb 22 08:08:02 2017 dylan renard
** Last update Sat Feb 25 16:54:53 2017 dylan renard
*/

#include "matchstick.h"
#include <stdlib.h>

t_playable		*find_best_move(int *map,
					int number_of_line,
					int max_num)
{
  t_info		*info;

  info = init_info();
  while (info->i != number_of_line)
    {
      info->map_copy = dup_map(number_of_line, map);
      play(info->i + 1, info->j, info->map_copy);
      info->bin_map = map_to_bin_map(number_of_line, info->map_copy);
      info->current_nim_sum = compute_nim_sum(info->bin_map);
      if (is_best_nim_sum(info->current_nim_sum, info->best_nim_sum) && info->j)
	{
	  info->best_nim_sum = info->current_nim_sum;
	  info->best = info_to_playable(info->i, info->j);
	  if (nim_sum_equal_zero(info->best_nim_sum))
	    return (info->best);
	}
      my_free(info->map_copy, info->bin_map);
      if (info->j == max_num || info->j >= map[info->i])
	next(info);
      else
	info->j++;
    }
  return (info->best);
}

int		check_state(int number_of_line, int max_num, int *map)
{
  int		i;
  int		count;
  int		normal;

  i = 0;
  count = 0;
  normal = 0;
  while (i != number_of_line)
    {
      if (map[i] > 1 && map[i] <= max_num)
	count++;
      if (map[i] > 1)
	normal++;
      i++;
    }
  if (count == 1 && normal == 1)
    return (1);
  if (count == 0 && normal == 0)
    return (2);
  else
    return (0);
}

bool		final_state(int *map, int number_of_line, int max_num)
{
  int		current_state;
  int		line;

  if ((current_state = check_state(number_of_line, max_num, map)) > 0)
    {
      if (current_state == 1)
	{
	  state1(map, number_of_line);
	}
      else if (current_state == 2)
	{
	  line = find_first_line(map, number_of_line);
	  play(line + 1, 1, map);
	  print_msg(line, 1);
	}
      return (true);
    }
  return (false);
}

int		smart_ai(int number_of_line, int max_num, int *map)
{
  char		**bin_map;
  char		*nim_sum;
  t_playable	*move;

  my_puts("\n\nAI's turn...");
  if (final_state(map, number_of_line, max_num))
    return (is_defeat(map) + 1);
  bin_map = map_to_bin_map(number_of_line, map);
  nim_sum = compute_nim_sum(bin_map);
  if (!nim_sum_equal_zero(nim_sum))
    {
      move = find_best_move(map, number_of_line, max_num);
      if (move != NULL)
	play(move->line + 1, move->match, map);
      my_putstr(my_strcat("AI removed ", to_string(move->match)));
      my_puts(my_strcat(" match(es) from line ", to_string(move->line)));
      return (is_defeat(map) + 1);
    }
  return (random_ai(number_of_line, max_num, map));
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
