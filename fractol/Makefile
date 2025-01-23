CC = cc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux -I../ft_printf -O3
LDFLAGS = -Lminilibx-linux -Lft_printf -lmlx -lX11 -lXext -lm -lftprintf

SRCS = burningship.c events.c fractol.c fractol_utils.c julia.c mandelbrot.c
OBJS = $(SRCS:.c=.o)

NAME = fractol

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX_DIR)

re: fclean all
