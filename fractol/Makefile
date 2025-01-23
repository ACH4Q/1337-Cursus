CC = cc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux -O3
LDFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm

SRCS = burningship.c events.c fractol.c fractol_utils.c julia.c mandelbrot.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

SECONDARY : $(OBJS)