# Compiler and flags
CC 			= clang++
CFLAGS 		= -Wall -Wextra -Werror -std=c++98

#Sources and objects
SRC = ClapTrap.cpp main.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)

NAME = ScavTrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp ScavTrap.hpp ClapTrap.hpp
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