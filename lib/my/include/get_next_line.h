/*
** get_next_line.h for get_next_line in /home/artha/CPE_2016_getnextline/src
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Thu Jan 12 13:22:18 2017 dylan renard
** Last update Sun Feb 26 16:46:46 2017 dylan renard
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define READ_SIZE	40000
# define FD		statique->fd != fd

typedef struct		s_info1
{
  int			ret;
  char			buf[READ_SIZE];
  char			*str;
  int			status;
  int			i;
}			t_info1;

typedef struct		s_return
{
  int			status;
  char			*rest;
}			t_return;

char			*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
