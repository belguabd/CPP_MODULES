FLAGS=c++ -Wextra -Wall -Werror -std=c++98

NAME=ex02

SRC=main.cpp

OBJ=$(SRC:.cpp=.o)


all : $(NAME)


$(NAME) :$(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Array.hpp
	$(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all 
