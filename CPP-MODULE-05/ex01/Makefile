FLAGS=c++ -Wextra -Wall -Werror -std=c++98

NAME=Exception

SRC=Bureaucrat.cpp Form.cpp main.cpp


HEADER=Bureaucrat.hpp Form.hpp


OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)


%.o:%.cpp $(HEADRE)
	$(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : all clean



