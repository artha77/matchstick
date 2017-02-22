/*
** my_strndup.c for my_strndup in /home/artha/signal_test
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sat Feb 18 13:31:05 2017 dylan renard
** Last update Sat Feb 18 13:35:34 2017 dylan renard
*/

#include <stdlib.h>
#include "my.h"

char	*my_strndup(char *src, int n)
{
  char	*dest;
  int	len;

  if (src == NULL)
    return (NULL);
  len = my_strlen(src) + 1;
  if ((dest = malloc(len * sizeof(*src))) == NULL)
    return (NULL);
  my_strncpy(dest, src, n);
  return (dest);
}
