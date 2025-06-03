cc=c++ -Wextra -Wall -Werror -std=c++98

NAME=FIXED

SRC=main.cpp Fixed.cpp

OBJ=$(SRC:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(cc) -o $(NAME) $(OBJ)


%.o: %.cpp Fixed.hpp
	$(cc) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all



