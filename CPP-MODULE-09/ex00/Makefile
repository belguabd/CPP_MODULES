CFLAGS=c++ -std=c++98 -Wall -Wextra -Werror 

HEADERS= BitcoinExchange.hpp

SRCS = main.cpp BitcoinExchange.cpp


OBJS = $(SRCS:.cpp=.o)


NAME= btc

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