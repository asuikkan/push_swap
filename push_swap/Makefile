# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 15:06:34 by asuikkan          #+#    #+#              #
#    Updated: 2022/04/26 15:06:36 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

INCS	= -I ./includes -I ./libft/includes

SRCS	= main.c stacker.c

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
