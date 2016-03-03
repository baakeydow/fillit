# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bndao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 08:41:27 by bndao             #+#    #+#              #
#    Updated: 2016/03/02 08:38:58 by bndao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fillit

SRC = main.c
SRC += get_map.c
SRC += check.c
SRC += tools.c
SRC += id.c
SRC += add.c
SRC += resolved.c
SRC += get_point.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall
FLAGS += -Wextra
FLAGS += -Werror

HEADERS = headers/included.h
HEADERS += headers/libft.h

LIBFT = libft.a

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c  $(SRC) $(HEADERS)
	@$(CC) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "\033[0;32mCreated...\033[0m"

allclean: fclean all clean

clean:
	@rm -f $(OBJECTS)
	@echo "\033[0;31m*.o gone abroad\033[0m"

fclean:
	@rm -f $(NAME) $(OBJECTS)
	@echo "\033[1;37mWiped !\033[0m"

re: fclean all
