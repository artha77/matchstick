##
## Makefile for my_printf in /home/artha/printf
## 
## Made by dylan renard
## Login   <artha@epitech.net>
## 
## Started on  Mon Nov  7 15:05:57 2016 dylan renard
## Last update Wed Feb 22 16:36:11 2017 dylan renard
##

CC	= 	gcc

RM	= 	rm -f

NAME	= 	matchstick

SRCS	=	src/main.c		\
		src/map.c		\
		src/utils.c		\
		src/gameplay.c		\
		src/get.c		\
		src/rand.c		\
		src/ai.c		\
		src/special_map.c	\
		src/debug_display.c	\
		#src/debug.c		\

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	+=	#-W -Wextra -Wall -Werror -pedantic

CFLAGS	+=	-I./include/

LDFLAGS +=	-L./lib -lmy -lgnl

all: libmy $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAFS) $(LDFLAGS) -lncurses

libmy:
	@$(MAKE) -C lib/my

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C lib/my

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, re, all, fclean
