# Compiler and flags
CC 			= c++
CFLAGS 		= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

#Sources and objects
SRC = 
OBJ = $(SRC:.cpp=.o)
HDR = $(SRC:.cpp=.hpp)

NAME = whatever

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) main.o

%.o: %.cpp $(HDR) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

main.o: main.cpp $(HDR) Makefile
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