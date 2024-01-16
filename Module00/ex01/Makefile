# Compiler and flags
CC 			= c++
CFLAGS 		= -Wall -Wextra -Werror -std=c++98

#Sources and objects
SRC = PhoneBook.cpp main.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp PhoneBook.hpp Contact.hpp
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