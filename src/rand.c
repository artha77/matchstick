/*
** rand.c for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Feb 21 15:51:07 2017 dylan renard
** Last update Tue Feb 21 16:07:19 2017 dylan renard
*/

#include "matchstick.h"
#include <stdlib.h>

int		range_rand(int min, int max)
{
  double	rand_num;

  rand_num = (double)rand() / RAND_MAX;
  return ((max - min + 1) * rand_num + min);
}
