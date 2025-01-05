FLAGE=c++  -Wextra -Wall -Werror -std=c++98 

NAME=FragTrap

SRC=main.cpp ClapTrap.cpp 

OBJ=$(SRC:.cpp=.o)

all :$(NAME)


$(NAME) :$(OBJ)
	$(FLAGE) $(OBJ) -o $(NAME)

%.o :%.cpp ClapTrap.hpp FragTrap.hpp ScavTrap.hpp
	$(FLAGE) -c $< -o $@

clean :	
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all 


