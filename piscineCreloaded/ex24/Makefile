# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 09:17:03 by cjulliar          #+#    #+#              #
#    Updated: 2016/11/04 14:38:53 by cjulliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJET= ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
SOURCE= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c \
	srcs/ft_swap.c
BIBLI= libft.a
WWW= -Wall -Werror -Wextra
HEADER = includes/ft.h

all:
	gcc -I $(HEADER) $(WWW) -c $(SOURCE)
	ar rc $(BIBLI) $(OBJET)
	ranlib $(BIBLI)

clean:
	/bin/rm -rf $(OBJET)

fclean: clean
	/bin/rm -rf $(BIBLI)

re: fclean all
