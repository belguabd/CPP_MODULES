# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:33:12 by belguabd          #+#    #+#              #
#    Updated: 2024/12/02 12:38:03 by belguabd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



FLAGS=c++ -Wall -Wextra -Werror -std=c++98

NAME=easyfind

SRC=main.cpp

OBJ=$(SRC:.cpp=.o)

all :$(NAME)


$(NAME):$(OBJ)	
	$(FLAGS)  $(OBJ) -o $(NAME)
%.o:%.cpp  Easyfind.hpp
	$(FLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:fclean  all
	