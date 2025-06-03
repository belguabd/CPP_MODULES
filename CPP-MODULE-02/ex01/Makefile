FLAGS=c++ -Wextra -Wall -Werror -std=c++98

NAME=FIXED


SRC=Fixed.cpp main.cpp 

OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Fixed.hpp
	$(FLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all