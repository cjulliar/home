# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconti <mconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 14:00:49 by tbehra            #+#    #+#              #
#    Updated: 2019/06/01 16:21:42 by nfinkel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= clang++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic
NAME	= ft_gkrellm
DEBUG	= debug_$(NAME)

NCURSE = -lncurses

OBJDIR	= obj

FAN		= -fsanitize=address,undefined -g

GREEN	= \x1b[32m

WHITE	= \x1b[0m

SRC		=	main.cpp		\
			Gui.cpp			\
			Monitor.cpp		\
			NCurses.cpp		\

OBJ		= $(SRC:.cpp=.o)

INC		=	

INC_PATH = ./

OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(addprefix $(INC_PATH)/, $(INC))

all:  $(OBJDIR) $(NAME)
	@echo > /dev/null

$(NAME): obj $(OBJP)
	@$(CC) $(CFLAGS) -o $@ $(OBJP) $(NCURSE) -I$(INC_PATH)
	@echo "${WHITE}$(NAME)			${GREEN}DONE${WHITE}"

debug: obj $(OBJP)
	@$(CC) $(CFLAGS) -o $(DEBUG) $(OBJP) $(NCURSE) -I$(INC_PATH) $(FAN)
	@echo "${WHITE}$(NAME)			${GREEN}DONE${WHITE}"

obj :
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(INCP)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC_PATH)

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAME) $(DEBUG)

re: fclean all
