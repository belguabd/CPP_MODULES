CFLAGS=c++ -std=c++98 -Wall -Wextra -Werror 

HEADERS= PmergeMe.hpp

SRCS = main.cpp PmergeMe.cpp


OBJS = $(SRCS:.cpp=.o)


NAME= PmergeMe

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
