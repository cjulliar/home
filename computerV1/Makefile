# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 15:03:03 by cpalmier          #+#    #+#              #
#    Updated: 2018/11/28 11:32:25 by cjulliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computer

SRC = src/main.c src/parseur.c src/resolution.c src/ft_nospace.c \
	  src/isolation.c src/reduced_forme.c src/reponse.c src/degre2.c \
	  src/parseur2.c

HEADER = include/computer.h libft/libft.h

OBJ = $(SRC:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	@gcc -Wall -Werror -Wextra \
		$(HEADER) $(SRC) libft/libft.a
	@mv a.out $(NAME)

clean :
	make -C libft clean
	@rm -rf $(OBJ)

fclean : clean
	make -C libft fclean
	@rm -rf $(NAME)

re : fclean all
