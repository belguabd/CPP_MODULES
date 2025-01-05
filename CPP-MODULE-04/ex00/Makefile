FLAGS=c++  -Wall -Wextra -Werror -std=c++98 

NAME=Animal

SRC=main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp 

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)


%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp 
	$(FLAGS) -c $< -o $@ 


clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)


re : fclean all 
