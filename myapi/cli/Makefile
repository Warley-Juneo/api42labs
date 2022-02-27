SOURCES = check_arguments.c count_method.c main.c print_cli.c
HEADER = cli.h

OBJ_SRC = $(SOURCES:%.c=%.o)

NAME 	= cli

CC		= gcc
RM		= rm -rf

.c.o: $(CC) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ_SRC) $(HEADER)
			$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

clean:
		$(RM) $(OBJ_SRC)

fclean: clean
		$(RM) $(OBJ_SRC) $(NAME)

re:		clean fclean all

.PHONY: all clean fclean re
