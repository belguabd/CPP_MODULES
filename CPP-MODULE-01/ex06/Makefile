FLAGS=c++ -Wextra -Wall -Werror -std=c++98


NAME=harlFilter

SRC=main.cpp Harl.cpp

OBJ=$(SRC:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)


%.o: %.cpp Harl.h
	$(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all