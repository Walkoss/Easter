NAME = easter

CC = gcc

SRC = src/easter_error.c 		\
	src/easter.c

OBJ = $(SRC:%.c=%.o)

LIB = libmy/libmy.a

FLAGS = -W -Wall -Wextra -Werror -pedantic -g

.PHONY: clean fclean re all

all:	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
