# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bndao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 08:41:27 by bndao             #+#    #+#              #
#    Updated: 2016/03/13 16:07:59 by bndao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCDIR = src/

SRC = $(SRCDIR)main.c \
		$(SRCDIR)get_map.c \
		$(SRCDIR)check.c \
		$(SRCDIR)tools.c \
		$(SRCDIR)id.c \
		$(SRCDIR)add.c \
		$(SRCDIR)resolved.c \
		$(SRCDIR)get_point.c

INC = inc

OBJ = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -I libft/includes -L libft/ -lft
	@echo "\033[0;32mCreated...\033[0m"
%.o:%.c
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I libft/includes

lib:
	@echo "-> Compiling libft..."
	@make -C ./libft

clean:
	@rm -f $(OBJ)
	@echo "\033[0;31m*.o gone abroad\033[0m"

allclean: fclean all clean

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "\033[1;37mWiped !\033[0m"

re: fclean all

.PHONY: $(NAME) all lib clean fclean re
