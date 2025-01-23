NAME = fractol
CFLAGS = -Iminilibx-linux -Lminilibx-linux -lmlx -lX11 -lXext -lm -O3
CC = cc

all : $(NAME)
$(NAME) : burningship.c events.c fractol.c fractol_utils.c julia.c mandelbrot.c 
	CC NAME -o NAME 
clean :
	rm -rf *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all
	