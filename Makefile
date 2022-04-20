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

SRCS	= main.c stacker.c swap.c input.c push.c

OBJS	= $(SRCS:.c=.o)

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

.PHONY: all clean fclean re
