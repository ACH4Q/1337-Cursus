CLIENT = ft_client.c
CLIENT_BONUS = ft_client_bonus.c

SERVER = ft_server.c
SERVER_BONUS = ft_server_bonus.c

UTILS = minitalk_utils.c
UTILS_BONUS = minitalk_utils_bonus.c

NAME = client
NAME_BONUS = client_bonus

NAME_2 = server
NAME_2_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS_CLIENT = $(CLIENT:.c=.o) $(UTILS:.c=.o)
OBJS_SERVER = $(SERVER:.c=.o) $(UTILS:.c=.o)
OBJS_CLIENT_BONUS = $(CLIENT_BONUS:.c=.o) $(UTILS_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SERVER_BONUS:.c=.o) $(UTILS_BONUS:.c=.o)

all: $(NAME) $(NAME_2)

bonus: $(NAME_BONUS) $(NAME_2_BONUS)

%.o: %.c
	@echo "Compiling \033[1;32m$<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_CLIENT)
	@echo "Linking \033[1;32m$@\033[0m"
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $@

$(NAME_2): $(OBJS_SERVER)
	@echo "Linking \033[1;32m$@\033[0m"
	@$(CC) $(CFLAGS) $(OBJS_SERVER) -o $@

$(NAME_BONUS): $(OBJS_CLIENT_BONUS)
	@echo "Linking \033[1;32m$@\033[0m"
	@$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) -o $@

$(NAME_2_BONUS): $(OBJS_SERVER_BONUS)
	@echo "Linking \033[1;32m$@\033[0m"
	@$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) -o $@

clean:
	@echo "Deleting all object files"
	@rm -f *.o

fclean: clean
	@echo "Deleting all executables"
	@rm -f $(NAME) $(NAME_2) $(NAME_BONUS) $(NAME_2_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

.SECONDARY : $(OBJS_SERVER) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT) $(OBJS_CLIENT_BONUS)