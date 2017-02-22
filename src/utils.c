/*
** utils.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Feb 21 13:31:14 2017 dylan renard
** Last update Tue Feb 21 13:31:23 2017 dylan renard
*/

#include "matchstick.h"

void		my_putstr_n_time(char *str, int n)
{
  while (n > 0)
    {
      my_putstr(str);
      n--;
    }
}
