# Compiler and flags
CC 			= c++
CFLAGS 		= -Wall -Wextra -Werror -std=c++98

#Sources and objects
SRC = Fixed.cpp Point.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
HDR = Fixed.hpp Point.hpp

NAME = fixed-point

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