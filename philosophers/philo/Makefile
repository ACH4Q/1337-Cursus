NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address

CFILES = $(wildcard *.c)
SOURCES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES)
	@echo "Building"
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c philo.h
	@echo "Compiling"
	@$(CC) $(CFLAGS)  $< -c -o $@

clean:
	@echo "Cleaning up"
	@rm -rf $(NAME) $(SOURCES)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
