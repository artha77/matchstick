/*
** get_next_line.h for get_next_line in /home/artha/CPE_2016_getnextline/src
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Thu Jan 12 13:22:18 2017 dylan renard
** Last update Sun Feb 26 21:24:05 2017 dylan renard
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define READ_SIZE	40000
# define FD		statique->fd != fd
# define REST		ret->rest
# define RETURN		return (NULL)
# define RET		contain_0(REST) && my_strlen(REST) == 0 && ret->str

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
  char			*str;
}			t_return;

char			*get_next_line(const int fd);
int			count_n(char *str);
int			contain_0(char *rest);
int			contain_n(char *rest);

#endif /* !GET_NEXT_LINE_H_ */
