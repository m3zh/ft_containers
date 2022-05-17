# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mlazzare          #+#    #+#              #
#    Updated: 2022/05/17 21:22:07 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers
VECTOR = vector
STACK = stack
MAP = map
SUBJECT = subject

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS	=	tests/main.cpp					\

INC		=	src/map.hpp						\
			src/stack.hpp					\
			src/vector.hpp					\

all: $(NAME)

$(NAME): $(SRCS) $(INC)
	$(CXX) $(CXXFLAGS) $(SRCS) -D ALL=1 -o $@

$(SUBJECT): $(SRCS)  $(INC)
	$(CXX) $(CXXFLAGS) $(SRCS) -D SUBJECT=1 -o $@

$(VECTOR): $(SRCS)  $(INC)
	$(CXX) $(CXXFLAGS) $(SRCS) -D VECTOR=1 -o $@

$(MAP): $(SRCS)  $(INC)
	$(CXX) $(CXXFLAGS) $(SRCS) -D MAP=1 -o $@

$(STACK): $(SRCS) $(INC)
	$(CXX) $(CXXFLAGS) $(SRCS) -D STACK=1 -o $@

clean: fclean

fclean:
	@rm -f $(NAME)
	@rm -f $(VECTOR)
	@rm -f $(MAP)
	@rm -f $(STACK)
	@rm -f $(SUBJECT)

re: fclean all
