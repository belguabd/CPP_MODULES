
FLAGS=c++ -std=c++98 -Wall -Wextra -Werror

NNAE=StringReplacer


SRC=main.cpp

OBJ=$(SRC:.cpp=.o)

all: $(NNAE)


$(NNAE): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NNAE)


%.o: %.cpp
	$(FLAGS) -c $< -o $@


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NNAE)

re : fclean all


