# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 16:41:22 by cjulliar          #+#    #+#              #
#    Updated: 2018/11/13 14:44:10 by cjulliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
		 ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat \
		 ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr \
		 ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum \
		 ft_isascii ft_isprint ft_toupper ft_tolower ft_memalloc ft_memdel \
		 ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap \
		 ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim \
		 ft_delspcbeg ft_delspcend ft_strsplit ft_itoa ft_putchar ft_putstr \
		 ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd \
		 ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
		 ft_lstmap ft_strfold ft_swap ft_isspace get_next_line ft_atoidouble \
		 ft_puissance ft_puissancedouble ft_isinteger ft_sqrtdouble ft_ismath \
		 ft_putdouble ft_absdouble ft_abs ft_upper ft_isnumeric

NAME = libft.a
HEADER = libft.h
WWW = -Wall -Werror -Wextra
EXE = exe

.PHONY: all
all: $(NAME)

$(NAME):
	@gcc -I $(HEADER) $(WWW) -c $(SOURCE:%=%.c)
	@ar rc $(NAME) $(SOURCE:%=%.o)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(SOURCE:%=%.o)

fclean: clean
	@/bin/rm -rf $(EXE)
	@/bin/rm -rf $(NAME)

re: fclean all
