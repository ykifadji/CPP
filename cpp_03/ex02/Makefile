#-------------------COLORS------------------#
DEF = \033[0m
YELLOW = \033[38;5;226m
RED = \033[31;2m
BOLD = \033[1m

#--------------------SRCS-------------------#
SRCS = main.cpp ClapTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)

#-------------------COMPILE------------------#
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#-------------------RULES-------------------#
NAME = fragtrap

all : $(NAME)

$(NAME): $(OBJS)
	@echo "	Compiling..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "	$(BOLD)$(YELLOW)Compiled successfully !$(DEF)"

clean:
	@rm -f $(OBJS)
	@echo "	$(BOLD)$(RED)Deleted file .o$(DEF)"

fclean: clean
	@rm -f $(NAME)
	@rm -f *.replace
	@echo "	$(BOLD)$(RED)Deleted file .a$(DEF)"

re: fclean all

.PHONY: all clean fclean re