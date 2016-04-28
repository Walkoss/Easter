NAME = crusader
CC = gcc
SRC = libmy/my_revstr.c \
	libmy/my_strcpy2.c \
	libmy/my_revstr_to_wordtab.c \
	libmy/my_strpos.c \
	src/easter.c 	\
	src/easter_check.c \
	src/easter_solve_diago.c 	\
	src/easter_solve_crossword.c 	\
	src/easter_init.c \
	src/easter_get_content.c
OBJ = $(SRC:%.c=%.o)
LIB = liblist/liblist.a libmy/libmy.a
CFLAGS = -W -Wall -Wextra -Werror -pedantic -g
.PHONY: clean fclean re all
all:	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
