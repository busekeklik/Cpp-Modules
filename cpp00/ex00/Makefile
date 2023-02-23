NAME	=	megaphone
SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:.cpp=.o)
CC		=	c++
RM		=	rm -f
FLAGS	=	-Wall -Werror -Wextra -std=c++98

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m


all: $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@printf "$(_SUCCESS) $(YELLOW)- Executable ready.\n$(RESET)"

clean:
		@$(RM) $(OBJS)
		@printf "$(GRAY)    - Object files removed.$(RESET)\n"

fclean:	clean
		@$(RM) $(NAME)
		@printf "$(GRAY)    - Executable removed.$(RESET)\n"

re:	fclean all
.PHONY: all clean fclean re bonus
