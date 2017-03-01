# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:48:48 by cjulliar          #+#    #+#              #
#    Updated: 2016/11/22 15:34:02 by cjulliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ft_display_file.c
EXECUTABLE = ft_display_file
WWW = -Wall -Werror -Wextra
OBJET = ft_disply_file.o

.PHONY: all

all:
	gcc $(WWW) -o $(EXECUTABLE) -c $(SOURCE) 
	ar rc truc.a $(OBJET)
	ranlib truc.a
clean:
	/bin/rm -rf $(OBJET)

fclean: clean
	/bin/rm -rf truc.a $(EXECUTABLE)

re: fclean all
