FLAGS=c++  -Wall -Wextra -Werror -std=c++98  #-fsanitize=address -g

NAME=Brain

SRC=main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)


%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp Brain.hpp
	$(FLAGS) -c $< -o $@ 


clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)


re : fclean all 
