FLAGS=c++  -fsanitize=address #-Wextra -Werror -Wall -std=c++98  


NAME=PmergeMe

SRC=main.cpp PmergeMe.cpp 

OBJ=$(SRC:.cpp=.o)


all : $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all 
