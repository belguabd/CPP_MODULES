FLAGS=c++ -Wextra -Werror -Wall -std=c++98
NAME=Exception

SRC=main.cpp AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

HEADER=AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME):$(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(FLAGS) -c $< -o $@


clean:
	$(RM) $(OBJ)
fclean :clean
	$(RM) $(NAME)


re: fclean all 












