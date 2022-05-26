# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 16:08:18 by asuikkan          #+#    #+#              #
#    Updated: 2022/05/26 16:08:20 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

NAME_C	= checker

DIR		= ./push_swap_srcs/

DIR_C	= ./checker_srcs/

INCS	= -I ./push_swap_srcs/includes -I ./libft/includes

INCS_C	= -I ./checker_srcs/includes -I ./libft/includes

SRCS	= main.c stacker.c stacksort.c push.c reverse.c rotate.c swap.c	\
		  finders.c positioners.c helpers.c

SRCS_C	= main.c stacker.c swap.c input.c push.c execute.c	\
		  fpointers.c rotate.c reverse.c

LIB		= -L ./libft -lft

NAME_G	= generator

SRCS_G	= numbergen.c

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) $(INCS) $(patsubst %,$(DIR)%,$(SRCS)) -o $(NAME) $(LIB)
	$(CC) $(FLAGS) $(INCS_C) $(patsubst %,$(DIR_C)%,$(SRCS_C)) -o $(NAME_C) $(LIB)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f $(NAME_C)

re: fclean all

gen:
	$(CC) $(FLAGS) $(SRCS_G) -o $(NAME_G)

.PHONY: all clean fclean re
