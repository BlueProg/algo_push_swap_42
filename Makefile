# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmole <mmole@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 17:04:02 by mmole             #+#    #+#              #
#    Updated: 2015/02/04 14:11:58 by mmole            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		main.c 
			
OBJ		=		$(SRC:.c=.o)

LIB		=		libft/libft.a

INC		=		libft/includes

NAME	=		push_swap

RM		=		rm -f

FLAG	=		-Wall -Werror -Wextra -g

all: libft/libft.a $(NAME)

$(NAME): $(OBJ)
		gcc $(FLAG) -o $(NAME) $(OBJ) -L. $(LIB)

%.o:		%.c
		gcc $(FLAG) -c $^ -o $@ -I $(INC)

libft/libft.a:
		make -C libft/

re:		fclean all

clean:
		@$(RM) $(OBJ)
		make -C libft/ clean

fclean: clean
		@$(RM) $(NAME)
		make -C libft/ fclean
		@$(RM) libft.h.gch

.PHONY: all clean fclean re
