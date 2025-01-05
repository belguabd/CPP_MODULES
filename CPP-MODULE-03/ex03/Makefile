FLAGE=c++  -Wextra -Wall -Werror -std=c++98 

NAME=DiamondTrap

SRC=main.cpp ClapTrap.cpp ScavTrap.cpp DiamondTrap.cpp FragTrap.cpp

OBJ=$(SRC:.cpp=.o)

all :$(NAME)


$(NAME) :$(OBJ)
	$(FLAGE) $(OBJ) -o $(NAME)

%.o :%.cpp ClapTrap.hpp ScavTrap.hpp DiamondTrap.hpp FragTrap.hpp 
	$(FLAGE) -c $< -o $@

clean :	
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
