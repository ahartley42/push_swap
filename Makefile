# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahartley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 16:29:39 by ahartley          #+#    #+#              #
#    Updated: 2019/09/16 15:33:28 by ahartley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap

NAME_C = checker

FLAGS = -Wall -Wextra -Werror

SRCS = 	in_cmd.c \
		libft/libft.a \
		new_link.c \
		normal.c \
		ps_algo.c \
		ps_algo_auto.c

INCL = -I.

all:
	make -C srcs/libft/ re
	gcc $(FLAGS) $(NAME_P).c $(INCL) $(SRCS) -o $(NAME_P)
	gcc $(FLAGS) $(NAME_C).c $(INCL) $(SRCS) -o $(NAME_C)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
