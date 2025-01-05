FLAGS=c++  -Wall -Wextra -Werror -std=c++98  #-fsanitize=address -g

NAME=Interface

SRC= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp 

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)


%.o: %.cpp AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp
	$(FLAGS) -c $< -o $@


clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)


re : fclean all 
