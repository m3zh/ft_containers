# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mlazzare          #+#    #+#              #
#    Updated: 2022/04/24 16:17:09 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container

CC = c++ #-fsanitize=address -g

CFLAGS = -Wall -Wextra -Werror -std=c++98

vector:
	@$(CC) $(CFLAGS) tests/vector.cpp -o $(NAME)

stack:
	@$(CC) $(CFLAGS) tests/stack.cpp -o $(NAME)

map:
	@$(CC) $(CFLAGS) tests/map.cpp -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@rm -rf *.dSYM

fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@rm -rf *.dSYM

re:	fclean all

.PHONY: all clean re fclean
