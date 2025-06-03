CFLAGS= c++ -std=c++98 -Wall -Wextra -Werror 

HEADERS= RPN.hpp

SRCS = main.cpp RPN.cpp


OBJS = $(SRCS:.cpp=.o)


NAME= RPN

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all