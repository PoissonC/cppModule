# Compiler and flags
CC 			= clang++
CFLAGS 		= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

#Sources and objects
SRC = Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)
HDR = $(SRC:.cpp=.hpp)

NAME = abstract

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) main.o

%.o: %.cpp $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

main.o: main.cpp $(HDR)
	$(CC) $(CFLAGS) -o main.o -c main.cpp

# Clean up object files
clean:
	rm -f $(OBJ) main.o
# Clean up object files and the library
fclean: clean
	rm -f $(NAME)
# Rebuild everything
re: fclean all
# By default, just run 'make all'
.DEFAULT_GOAL := all