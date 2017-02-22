/*
** main.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Feb 21 09:22:03 2017 dylan renard
** Last update Wed Feb 22 16:35:30 2017 dylan renard
*/

#include "matchstick.h"

bool		argument_are_valid(int ac, char **av)
{
  if (ac == 3)
    {
      if (!(my_str_isnum(av[1]) && my_str_isnum(av[2])))
	return (my_puterr("matchstick take only number in parameter"),  false);
      else if (int_overflow(av[1]) || int_overflow(av[2]))
	return (my_puterr("parameters must fit in an int"),  false);
      else if (!(my_atoi(av[1]) >= 1 && my_atoi(av[1]) <= 100))
	return (my_puterr("number of line must be between 1 and 100"),  false);
      return (true);
    }
  else
    return (my_puterr("Invalid number of parameters."), false);
}

int		main(int ac, char **av)
{
  int		*matchstick_map;
  int		who_win;

  //if (my_strcmp(av[1], "--debug") == 0)
    //return (debug());
  if (argument_are_valid(ac, av))
    {
      if ((matchstick_map = map_generator(my_atoi(av[1]))) == NULL)
	return (84);
      who_win = start_game(my_atoi(av[1]), my_atoi(av[2]), matchstick_map);
      return (who_win);
    }
  else return (84);
}
