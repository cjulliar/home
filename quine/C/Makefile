NAME1 = Colleen
NAME2 = Grace
NAME3 = Sully

CC = gcc $(FLAGS)
FLAGS = -Wall -Wextra -Werror

SRC1 = Colleen.c
SRC2 = Grace.c
SRC3 = Sully.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1):	$(LIB) $(OBJ1)
	$(CC) -o $(NAME1) $(OBJ1)
$(NAME2):	$(LIB) $(OBJ2)
	$(CC) -o $(NAME2) $(OBJ2)
$(NAME3):	$(LIB) $(OBJ3)
	$(CC) -o $(NAME3) $(OBJ3)

fclean:
	rm -f $(OBJ1) $(NAME1) $(OBJ2) $(NAME2) $(OBJ3) $(NAME3)

re:				fclean all

.PHONY:			all re fclean

.SILENT:
%.o: %.c
	$(CC) -c $< -o $@
