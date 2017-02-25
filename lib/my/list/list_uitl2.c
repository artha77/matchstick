/*
** list_uitl2.c for push_swap in /home/artha/pushswap
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Nov 27 12:48:32 2016 dylan renard
** Last update Fri Feb 24 09:25:12 2017 dylan renard
*/

#include "my.h"
#include "list.h"
#include <stdlib.h>

void		free_list(t_ld *list)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      if (tmp == NULL)
	free(list->end);
      else
	free(tmp->prev);
    }
  free(list);
}

t_ld		*pop_list(t_ld  *list)
{
  t_list	*tmp;

  tmp = list->next;
  if (tmp != NULL)
    {
      if (tmp->next == NULL)
	{
	  free(list->next);
	  list->next = NULL;
 	  list->end = NULL;
	}
      else
	{
	  list->next = tmp->next;
	  free(tmp);
	  (list->next)->prev = NULL;
	}
    }
  return (list);
}

t_ld		**listA_to_listB(t_ld **list)
{
  if (list[LA]->next != NULL)
    {
      list[LB] = push_begin_list(list[LB], (list[LA]->next)->number);
      list[LA] = pop_list(list[LA]);
    }
  return (list);
}

t_ld		**listB_to_listA(t_ld **list)
{
  if (list[LB]->next != NULL)
    {
      list[LA] = push_begin_list(list[LA], (list[LB]->next)->number);
      list[LB] = pop_list(list[LB]);
    }
  return (list);
  }
