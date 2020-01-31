# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahartley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 16:29:39 by ahartley          #+#    #+#              #
#    Updated: 2019/09/17 09:36:43 by ahartley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap

NAME_C = checker

FLAGS = -Wall -Wextra -Werror

SRC_P = pre_check.c \
		in_cmd.c \
		libft/libft.a \
		new_link.c \
		normal.c \
		ps_algo.c \
		ps_algo_auto.c \
		flags.c

SRC_C = pre_check.c \
		in_cmd.c \
		libft/libft.a \
		new_link.c \
		normal.c \
		flags.c

all:
	@make -C libft/ re
	@gcc $(FLAGS) $(NAME_P).c $(SRC_P) -o $(NAME_P)
	@gcc $(FLAGS) $(NAME_C).c $(SRC_C) -o $(NAME_C)

$(NAME_P):
	@make -C libft/ re
	@gcc $(FLAGS) -g $(NAME_P).c $(SRC_P)

$(NAME_C):
	@make -C libft/ re
	@gcc $(FLAGS) -g $(NAME_C).c $(SRC_C)

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME_P)
	@/bin/rm -f $(NAME_C)

re: fclean all