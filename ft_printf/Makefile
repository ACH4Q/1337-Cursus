NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_DIR = ./includes
SOURCE_DIR = ./sources

CFILES = $(wildcard $(SOURCE_DIR)/*.c)
SOURCES = $(CFILES:.c=.o)

./$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c ./$(INCLUDE_DIR)/ft_printf.h
	@echo "\033[0;33m[*] compiling $?\033[0m"
	@$(CC) $(CFLAGS) $< -c -o $@

all: $(NAME)

$(NAME): $(SOURCES)
	@echo "\033[0;32m[+] archiving *.o onto $(NAME)\033[0m"
	@$(AR) rcs $@ $?

clean:
	@echo "\033[1;31m[!] deleting *.o\033[0m"
	@rm -rf $(SOURCES) *.out

fclean: clean
	@echo "\033[1;31m[!] deleting $(NAME) and *.o\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re