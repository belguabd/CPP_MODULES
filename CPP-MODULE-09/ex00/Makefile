FLAGS=c++ #-Wall -Werror -Wextra -std=c++98 #-fsanitize=address

NAME=btc

SRC=BitcoinExchange.cpp main.cpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all 

