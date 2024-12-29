CLIENT = ft_client.c
CLIENT_BONUS = ft_client_bonus.c

SERVER = ft_server.c
SERVER_BONUS = ft_server_bonus.c

UTILS =  minitalk_utils.c 
UTILS_BONUS = minitalk_utils_bonus.c 

NAME = client
NAME_BONUS = client_bonus

NAME_2 = server
NAME_2_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME_2)

bonus: $(NAME) $(NAME_2) $(NAME_BONUS) $(NAME_2_BONUS)

$(NAME):
	@echo "compiling \033[1;32m$(CLIENT)\033[0m"
	@$(CC) $(CFLAGS) $(CLIENT) $(UTILS) -o $@

$(NAME_2):
	@echo "compiling \033[1;32m$(SERVER)\033[0m"
	@$(CC) $(CFLAGS) $(SERVER) $(UTILS) -o $@

$(NAME_BONUS):
	@echo "compiling \033[1;32m$(CLIENT_BONUS)\033[0m"
	@$(CC) $(CFLAGS) $(CLIENT_BONUS) $(UTILS_BONUS) -o $@

$(NAME_2_BONUS):
	@echo "compiling \033[1;32m$(SERVER_BONUS)\033[0m"
	@$(CC) $(CFLAGS) $(SERVER_BONUS) $(UTILS_BONUS) -o $@

clean:
	@echo "deleting all the executable files"
	@rm -f $(NAME) $(NAME_2) $(NAME_BONUS) $(NAME_2_BONUS)

fclean: clean
	@echo "deleting *.a"
	@rm -f *.a

re: fclean all

.PHONY: all clean fclean re bonus