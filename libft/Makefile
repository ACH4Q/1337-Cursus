NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MANSRC = $(wildcard *.c)


SOURCES = $(MANSRC:.c=.o)

%.o: %.c
	 
	@$(CC) $(CFLAGS) -c $?

all: $(NAME)

$(NAME): $(SOURCES)

	@$(AR) rcs $@ $?

clean:
	@rm -f $(SOURCES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
