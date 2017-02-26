/*
** matchstick.h for matchstick in /home/artha/CPE_2016_matchstick
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Feb 21 09:26:26 2017 dylan renard
** Last update Sun Feb 26 20:48:00 2017 dylan renard
*/

#ifndef MATCHSTICK_H_
# define MATCHSTICK_H_
# define AI_WIN		2
# define USER_WIN	1
# define LINE_INVALID	1
# define ERR_INPUT	"Error: invalid input (positive number expected)\n"
# define ERR_ZERO	"Error: you have to remove at least one match\n"
# define ERR_LIM0	"Error: you cannot remove more than "
# define ERR_LIM1	my_strcat(ERR_LIM0, to_string(max_num))
# define ERR_LIMIT	my_strcat(ERR_LIM1, " matches per turn\n")
#include "my.h"
#include "get_next_line.h"

typedef enum {
  true = 1,
  false = 0,
}			bool;

typedef struct		s_playable
{
  int			line;
  int			match;
}			t_playable;

typedef struct		s_info
{
  t_playable		*best;
  char			*best_nim_sum;
  char			*current_nim_sum;
  int			*map_copy;
  char			**bin_map;
  int			i;
  int			j;
}			t_info;

bool			argument_are_valid(int, char **);
int			debug(void);
int			*map_generator(int number_of_line);
void			display_game(int number_of_line, int *map);
void			my_putstr_n_time(char *str, int n);
int			start_game(int number_of_line, int max_num, int *map);
int			turn_of_user(int number_of_line, int max_num, int *map);
int			turn_of_AI(int number_of_line, int max_num, int *map);
int			get_line(char *msg, int number_of_line);
int			get_match(char *msg, int line, int max_num, int *map);
bool			verif_line(char *line, int number_of_line);
bool			verif_match(char *match, int line, int max_num, int *);
void			play(int line, int match, int *map);
int			is_defeat(int *map);
int			range_rand(int min, int max);
int			random_ai(int number_of_line, int max_num, int *map);
void			display_bin_map(char **bin_map);
void			display_pair_map(char **pair_map);
void			display_bin_map_line(char *bin);
void			display_pair_map_line(char *pair_line);
char			**bin_map_to_pair_map(int number_of_line, char **);
char			*bin_line_to_pair_line(char *bin_line);
char			**map_to_bin_map(int number_of_line, int *map);
char			*char_to_bit(int c);
int			*dup_map(int number_of_line, int *map);
t_playable		*info_to_playable(int line, int match);
void			free_bin_map(char **bin_map);
void			my_free(int *map_copy, char **bin_map);
void			next(t_info *info);
t_info			*init_info(void);
void			display_nim_sum(char *nim_sum);
char			*compute_nim_sum(char **binmap);
char			compute_nim_row(char **bin_map, int row);
int			nim_sum_equal_zero(char *nim_sum);
bool			is_best_nim_sum(char *current, char *best);
int			smart_ai(int number_of_line, int max_num, int *map);
int			is_pair(int *map, int number_of_line);
int			find_first_line(int *map, int number_of_line);
void			print_msg(int line, int match);
int			find_line(int *map, int number_of_line);
void			state1(int *map, int number_of_line);
#endif /* !MATCHSTICK_H_ */
