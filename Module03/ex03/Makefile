# Compiler and flags
CC 			= c++
CFLAGS 		= -Wall -Wextra -Werror -std=c++98 #-Wshadow -Wno-shadow

#Sources and objects
SRC = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = $(SRC:.cpp=.o)
HDR = ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp ClapTrap.hpp

NAME = DiamondTrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HDR)
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