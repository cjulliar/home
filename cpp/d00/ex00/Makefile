NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

COMP = clang++
FLAGS = -Wall -Werror -Wextra


.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	$(COMP) -o $(NAME) $(OBJ) 

%.o : %.c
	@$(COMP) ${FLAGS} -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
