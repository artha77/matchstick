/*
** get.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Feb 21 15:25:35 2017 dylan renard
** Last update Sat Feb 25 12:48:59 2017 dylan renard
*/

#include "matchstick.h"

bool		verif_match(char *match, int line, int max_num, int *map)
{
  int		match_number;

  if (!(my_str_isnum(match)))
    return (my_puterr(ERR_INPUT), false);
  if (!(int_overflow(match)))
    {
      match_number = my_atoi(match);
      if (match_number < 1 || match_number > max_num)
	return (my_puterr((match_number < 1) ? ERR_ZERO : ERR_LIMIT), false);
      else if (map[line - 1] < match_number)
	return (my_puterr("Error: not enough matches on this line\n"), false);
      else
	return (true);
    }
  else return (my_puterr(ERR_LIMIT), false);
}

int		get_match(char *msg, int line, int max_num, int *map)
{
  char		*str;

  my_putstr(msg);
  str = get_next_line(0);
  if (verif_match(str, line, max_num, map))
    return (my_atoi(str));
  else
    return (-1);
}

bool		verif_line(char *line, int number_of_line)
{
  int		line_number;

  if (my_str_isnum(line))
    {
      if (int_overflow(line))
	return (my_puterr("Error: this line is out of range\n"), false);
      line_number = my_atoi(line);
      if (line_number <= 0 || line_number > number_of_line)
	return (my_puterr("Error: this line is out of range\n"), false);
      else
	return (true);
    }
  else
    return (my_puterr(ERR_INPUT), false);
}

int		get_line(char *msg, int number_of_line)
{
  char		*str;
  int		line;

  my_putstr(msg);
  line = -1;
  while (line == -1)
    {
      str = get_next_line(0);
      if (verif_line(str, number_of_line))
	line = my_atoi(str);
      else
	my_putstr(msg);
    }
  return (line);
}
