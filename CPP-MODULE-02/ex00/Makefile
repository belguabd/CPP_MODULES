FLAGS=c++ -Wall -Wextra -Werror -std=c++98

NAME=FIXED_POINT

SRCS=main.cpp Fixed.cpp

OBJS=$(SRCS:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Fixed.hpp
	$(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all