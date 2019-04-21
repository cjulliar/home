NAME = ft_ssl

SRC = src/main.c
	   

HEADER = -Ilibft -Iinclude

OBJ = $(SRC:.c=.o)

COLOR = \033[1;33m
COLOR_OFF = \033[0m

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	@gcc -Wall -Werror -Wextra $(HEADER) $(SRC) libft/libft.a
	@mv a.out $(NAME)
	@echo "${COLOR}all : $(NAME) created √${COLOR_OFF}"

./%.o : src/%.c
	@gcc -Wall -Werror -Wextra -c $< -o $@ -I $(HEADER) libft/libft.a

clean :
	make -C libft clean
	@rm -rf $(OBJ)
	@echo "${COLOR}$(NAME) clean √${COLOR_OFF}"

fclean : clean
	make -C libft fclean
	@rm -rf $(NAME)
	@echo "${COLOR}$(NAME) fclean √${COLOR_OFF}"

re : fclean all
