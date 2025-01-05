FLAGS=c++ -Wall -Wextra  -Werror -std=c++98

NAME=Zombie

SRC=main.cpp Zombie.cpp  randomChump.cpp newZombie.cpp 

HEADERS=Zombie.hpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp  $(HEADERS)
	$(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)


fclean :clean
	$(RM) $(NAME)


re: fclean all 
