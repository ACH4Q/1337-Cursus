CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isdigit.c ft_memcpy.c ft_bzero.c ft_strdup.c \
        ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c ft_strjoin.c \
        ft_strncmp.c ft_tolower.c ft_isalnum.c ft_itoa.c ft_memset.c \
        ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalpha.c ft_memchr.c \
        ft_split.c ft_strlcpy.c ft_strrchr.c ft_atoi.c ft_isascii.c \
        ft_memcmp.c ft_strchr.c ft_strlen.c ft_strtrim.c ft_strmapi.c \
        ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
        ft_putnbr_fd.c
SRCS_BNS = ft_lstnew_bonus.c  ft_lstadd_front_bonus.c 

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BNS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

bonus: $(OBJS) $(OBJS_BNS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BNS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus