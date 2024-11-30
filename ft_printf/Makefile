# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Project name
NAME = libftprintf.a
TEST_EXEC = test_printf

# Source files
MANDATORY_SRC = ft_printf.c ft_printnb.c ft_printhex.c ft_printunsnb.c ft_putchar.c ft_putstr.c
BONUS_SRC = ft_bonus_flag.c

# Object files
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Default target
all: $(NAME)

# Build library with mandatory files
$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $(MANDATORY_OBJ)

# Add bonus files to the library
bonus: $(MANDATORY_OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

# Build and run the test for mandatory files
test: all
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o $(TEST_EXEC)
	./$(TEST_EXEC)

# Build and run the test for bonus files
test_bonus: bonus
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o $(TEST_EXEC)
	./$(TEST_EXEC)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)

# Clean object files and the library
fclean: clean
	rm -f $(NAME) $(TEST_EXEC)

# Rebuild the library
re: fclean all
