FLAGS=c++ -Wextra -Wall -Werror -std=c++98
NAME=dynamic_cast


SRC=Base.cpp Utils.cpp main.cpp

HEADER=A.hpp B.hpp Base.hpp C.hpp Utils.hpp

OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME) : $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all



