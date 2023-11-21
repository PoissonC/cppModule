# Compiler and flags
CC 			= clang++
CFLAGS 		= -Wall -Wextra -Werror -std=c++98

#Sources and objects
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

NAME = tests

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Account.hpp
	$(CC) $(CFLAGS) -o $@ -c $<

# Clean up object files
clean:
	rm -f $(OBJ)
# Clean up object files and the library
fclean: clean
	rm -f $(NAME)
# Rebuild everything
re: fclean all
# By default, just run 'make all'
.DEFAULT_GOAL := all