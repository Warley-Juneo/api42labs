# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 14:06:42 by wjuneo-f          #+#    #+#              #
#    Updated: 2022/02/27 13:28:58 by wjuneo-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = main.c mongoose.c get_method.c response_bd.c response_client.c
HEADER = mongoose.h

OBJ_PATH = objects

OBJ_SRC = $(SOURCES:%.c=$(OBJ_PATH)/%.o)

NAME 	= apiserver

CC		= gcc
RM		= rm -rf

$(OBJ_PATH)/%.o: %.c
			$(CC) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ_PATH) $(OBJ_SRC) $(HEADER)
			$(CC) $(CFLAGS) -g3 $(OBJ_SRC) -lmysqlclient -o $(NAME)

$(OBJ_PATH):
			mkdir -p $(OBJ_PATH)

clean:
			$(RM) $(OBJ_PATH)

fclean: clean
			$(RM) $(OBJ_PATH) $(NAME)

re:			clean fclean all

run:		$(NAME)
			./$(NAME)

.PHONY: all clean fclean re
