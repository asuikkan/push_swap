# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 17:18:53 by asuikkan          #+#    #+#              #
#    Updated: 2022/04/15 17:18:54 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

NAME	= checker

INCS	= -I ./includes -I ./libft/includes

SRCS	= main.c stacker.c swap.c input.c push.c list.c execute.c	\
		  fpointers.c rotate.c reverse.c

OBJS	= $(SRCS:.c=.o)

NMB_NM	= generator

NMB_SRC	= numbergen.c

LIB		= -L ./libft -lft

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) $(INCS) $(SRCS) -o $(NAME) $(LIB)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

gen:
	$(CC) $(FLAGS) $(NMB_SRC) -o $(NMB_NM)

.PHONY: all clean fclean re
