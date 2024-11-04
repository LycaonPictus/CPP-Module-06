
COMPILER = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = serializer
SRC = Serializer.cpp
HEADERS = Serializer.hpp Data.hpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HEADERS)
	@echo "\033[0;32mCompiling $(notdir $@)\033[0m"
	@$(COMPILER) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(HEADERS) main.cpp
	@echo "\033[0;32mCompiling $(NAME)\033[0m"
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ) main.cpp
	@echo "\033[0;32mCompilation completed\033[0m"

all: $(NAME)

clean:
	@echo "\033[0;31mCleaning objects...\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[0;31mCleaning $(NAME)...\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
