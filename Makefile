NAME = crusader
CC = gcc
SRC = src/easter.c 	\
	src/easter_check.c
OBJ = $(SRC:%.c=%.o)
LIB =  liblist/liblist.a libmy/libmy.a
FLAGS = -W -Wall -Wextra -Werror -pedantic -g
.PHONY: clean fclean re all
all:	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all