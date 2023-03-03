SRC = main.cpp Fixed.cpp
OBJ	= $(SRC:.cpp=.o)
CXX	= c++
RM	= rm -rf
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
NAME = fixed

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m


all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@printf "$(GREEN) $(CURSIVE)- Executable ready.\n$(RESET)"

clean:
	@$(RM) $(OBJ)
	@printf "$(YELLOW) $(CURSIVE)   - Object files removed.$(RESET)\n"
fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW) $(CURSIVE)   - Executable removed.$(RESET)\n"

re: fclean $(NAME)
