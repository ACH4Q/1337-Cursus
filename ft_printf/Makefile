CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

MANDATORY_SRCS = ft_printf.c \
				  ft_printhex.c \
				  ft_printnb.c \
				  ft_printunsnb.c \
				  ft_putchar.c \
				  ft_putstr.c

BONUS_SRCS = ft_printf_bonus.c \
			  ft_printhex_bonus.c \
			  ft_printnb_bonus.c \
			  ft_printunsnb_bonus.c \
			  ft_putchar_bonus.c \
			  ft_putstr_bonus.c

MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
BONUS_OBJS     = ${BONUS_SRCS:.c=.o}

all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	ar rcs ${NAME} ${MANDATORY_OBJS}

bonus: ${MANDATORY_OBJS} ${BONUS_OBJS}
	ar rcs ${NAME} ${MANDATORY_OBJS} ${BONUS_OBJS}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${MANDATORY_OBJS} ${BONUS_OBJS}

fclean: clean
	rm -f ${NAME}


re: fclean all

.PHONY: all bonus clean fclean re
