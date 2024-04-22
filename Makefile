# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:22:25 by pablogon          #+#    #+#              #
#    Updated: 2024/04/22 21:43:12 by pablogon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = main.c \
	input_check.c input_check_utils.c \
	initiation.c \
	stack.c \
	push.c swap.c rotate.c reverse_rotate.c \
	tiny_sort.c sort.c \
	position.c cost.c moving.c \
	another_utils.c

OFILES = $(SRCS:.c=.o)
INCLUDE = push_swap.h

all: $(NAME)

$(NAME):$(OFILES) $(INCLUDE)
	$(CC) -o $(NAME) $(OFILES) 

bonus: $(NAME) $(BOFILES) $(INCLUDE)
	$(LIB) $(NAME) $(BOFILES) 
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re 