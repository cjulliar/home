# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 11:44:30 by cjulliar          #+#    #+#              #
#    Updated: 2017/10/09 03:18:30 by cjulliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = main ft_fenetre ft_initialisation ft_loop_event ft_loop_suite  \
		 ft_premieraffichage ft_affichermur ft_put_pixel \
		 ft_croisehoriz ft_croiseverti \
		 ft_degre ft_radian ft_divinf ft_mouvements \
		 ft_lectmap ft_lectprincipal ft_palette\
		 ft_laby1 ft_laby2 ft_laby3 ft_laby4 ft_mhori ft_mverti

SOURCEDIR = $(addprefix src/,$(SOURCE:%=%.c))

OBJETDIR = $(SOURCE:%=%.o)

NAME = libft/libft.a

HEADER = wolf3d.h

WWW = -Wall -Werror -Wextra

EXEC = wolf3d

MF = make fclean

L = -L/usr/local/lib/

I = -I/usr/local/include -I/Library/Frameworks/SDL2.framework/Headers/

SDL = -F/Library/Frameworks -framework SDL2

.PHONY: all clean fclean re

all: $(EXEC)

$(EXEC):
	make -C libft/
	gcc $(SDL) $(WWW) -o $(EXEC) -I $(HEADER) $(NAME) $(SOURCEDIR) $(L) $(I)

clean:
	make clean -C libft/
	@/bin/rm -rf $(OBJETDIR)

fclean: clean
	/bin/rm -rf $(EXEC)

re: fclean all

