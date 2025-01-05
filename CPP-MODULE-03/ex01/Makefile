FLAGE=c++  -Wextra -Wall -Werror -std=c++98

NAME=ScavTrap

SRC=main.cpp ClapTrap.cpp ScavTrap.cpp 

OBJ=$(SRC:.cpp=.o)

all :$(NAME)


$(NAME) :$(OBJ)
	$(FLAGE) $(OBJ) -o $(NAME)

%.o :%.cpp ClapTrap.hpp ScavTrap.hpp 
	$(FLAGE) -c $< -o $@

clean :	
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all 


