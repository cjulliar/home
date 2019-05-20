NAME = PhoneBook

SRC = main.cpp Contact.class.cpp
OBJ = $(SRC:.cpp=.o)
CLASS = Contact.class.hpp

COMP = clang++
FLAGS = -Wall -Werror -Wextra


.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(CLASS)
	$(COMP) -o $(NAME) $(OBJ) 

%.o : %.c
	@$(COMP) ${FLAGS} -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
