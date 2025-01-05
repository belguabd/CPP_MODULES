FLAGS=c++ -Wextra -Wall -Werror -std=c++98

SRC=main.cpp Harl.cpp

NAME=harl
OBJ=$(SRC:.cpp=.o)

all: $(NAME)
	

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp  Harl.hpp
	$(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all