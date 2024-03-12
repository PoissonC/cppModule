# Compiler and flags
CC 			= c++
CFLAGS 		= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

#Sources and objects
SRC = main.cpp Base.cpp Funcs.cpp
OBJ = $(SRC:.cpp=.o)
HDR = Base.hpp A.hpp B.hpp C.hpp Funcs.hpp

NAME = identify

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HDR) Makefile
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
.PHONY: all re fclean clean
