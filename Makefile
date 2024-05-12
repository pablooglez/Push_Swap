# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:22:25 by pablogon          #+#    #+#              #
#    Updated: 2024/05/12 18:26:14 by pablogon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME				= push_swap
NAME_B				= checker

SRCS	=	main.c \
	input_check.c input_check_utils.c \
	initiation.c \
	stack.c \
	push.c swap.c rotate.c reverse_rotate.c \
	tiny_sort.c sort.c \
	position.c cost.c moving.c \
	another_utils.c \
	split.c \
	ft_strjoin_c.c

SRCS_B	= checker.c \
		another_utils_bonus1.c another_utils_bonus2.c\
		input_check_bonus.c input_check_utils_bonus.c \
		ft_strjoin_c_bonus.c split_bonus.c \
		push_bonus.c rotate_bonus.c reverse_rotate_bonus.c swap_bonus.c \
		stack_bonus.c \

INC_DIR				= ./inc/
OBJ_DIR				= ./build/obj/
LIB_DIR				= ./build/lib/
LIBFT_INC			= ./src/libft/
LIBFT_DIR			= ./src/libft/
LIBFT				= libft.a

SRC_DIR				= ./src/$(NAME)/
SRC_DIR_B 			= ./src/$(NAME_B)/

SRC_INC = inc

all: $(NAME)

OBJS		= $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS		= $(OBJS:.o=.d)
-include $(DEPS)

$(NAME): $(OBJS)
# $(NAME): libft_comp $(OBJS)
	@printf "Compiling... $(NAME) \n"
	@$(CC) $(FLAGS) -I$(INC_DIR) $(OBJS) -o $(NAME);
# $(CC) $(FLAGS) -I$(INC_DIR) $(OBJS) $(LIB_DIR)$(LIBFT) -o $(NAME);

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@printf "Compiling... $< \n"
	@$(CC) $(FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -MMD -o $@ -c $<

OBJS_B		= $(SRCS_B:%.c=$(OBJ_DIR)%.o)
DEPS_B		= $(OBJS_B:.o=.d)
-include $(DEPS_B)

bonus: $(OBJS_B)
# bonus: libft_comp $(OBJS_B)
	@printf "Compiling... $(NAME_B) \n"
	@$(CC) $(FLAGS) -I$(INC_DIR) $(OBJS_B) -o $(NAME_B);
# $(CC) $(FLAGS) -I$(INC_DIR) $(OBJS_B) $(LIB_DIR)$(LIBFT) -o $(NAME_B);

$(OBJ_DIR)%.o: $(SRC_DIR_B)%.c
	@mkdir -p $(@D)
	@printf "Compiling... $< \n"
	@$(CC) $(FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -MMD -o $@ -c $<

libft_comp:
	@make -s all -C $(LIBFT_DIR)/; exit 0

clean:
	@-rm -f $(OBJS) $(OBJS_B) build/obj/*.d

fclean: clean
	@-rm -f $(OBJS) $(OBJS_B) $(NAME) $(NAME_B);
	@-rm -d $(LIB_DIR) >/dev/null 2>&1 || true
	@-rm -rf ./build >/dev/null 2>&1 || true

re: fclean all
.PHONY: all clean fclean re 