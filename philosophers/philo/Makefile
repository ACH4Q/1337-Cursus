CC = cc
CFLAG = -Wall -Wextra -Werror  -fsanitize=thread

FILE = $(wildcard *.c)

NAME = philo
OBJ = $(FILE:.c=.o)

	

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -lpthread $(OBJ) -o $@
%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

build:all clean
re : fclean all
.PHONY: all re fclean clean 
