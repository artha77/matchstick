/*
** my_signal.h for my_signal in /home/artha/signal_test/src
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Fri Feb 10 11:25:47 2017 dylan renard
** Last update Sun Feb 19 09:44:49 2017 dylan renard
*/

#ifndef MY_SIGNAL_H_
# define MY_SIGNAL_H_

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_packet
{
  char			*data;
  int			size;
  int			pos;
}			t_packet;

typedef struct		s_map_info
{
  char			*len;
  char			*first;
  char			*last;
}			t_map_info;

char			**map_fill(void);
char			**draw_on_map(t_map_info *, char **);
void			display_map(char **);
char			**map_gen(t_map_info **);
char			**map_load(char *);
int			verif_arg1(char *);
int			verif_arg2(char *);
int			calc_pos_len(char *, char *);
int			verif_len(t_map_info *);
int			same_len(char *, char *, char *, char*);
t_map_info		*str_cut(char *);
int			is_num(char *);
void			make_cross(char *, char **);
void			make_round(char *, char **);
int			sig_start_wait(char *);
int			sig_start(int, char *);
void			start_handle(int, siginfo_t *, void *);
void			sig_connect(int, siginfo_t *, void *);
int			player1_start(char **);
int			player2_start(char **);
char			*char_to_bit(char);
int			packet_convert(char *, char *);
int			verif_pid(int, int);
void			ping_handle(int, siginfo_t *, void *);
int			send_bit_to_pid(int, char *);
int			signal_send(int, char *);
char			*packet_fill(void);
char			packet_manage(char *, int);
void			game_handle(int, siginfo_t *, void *);
int			send(char **, char **);
int			wait(char **, char **);
int			is_victory(int, int);
void			istouch_handle(int, siginfo_t *, void *);
int			is_touch(char **, char *);
int			stat_touch(char *, int);
void			touch_handle(int, siginfo_t *, void *);
int			have_touch(char **);
int			wait_player(char **, char **);
void			display_info(char **, char **);
void			show_manual(void);
#endif /* !MY_SIGNAL_H_ */
