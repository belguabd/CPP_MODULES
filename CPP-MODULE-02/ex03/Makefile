FLAGS=c++ -Wextra -Wall -Werror  -std=c++98

NAME=TRIANGLE


SRC=main.cpp Point.cpp Fixed.cpp bsp.cpp

OBJ=$(SRC:.cpp=.o)	


all: $(NAME)


$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)



%.o: %.cpp Point.hpp
	$(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all