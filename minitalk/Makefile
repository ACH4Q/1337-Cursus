NAME_CLIENT = client
NAME_SERVER = server
SRCS_CLIENT = ft_client.c minitalk_utils.c minitalk_utils1.c
SRCS_SERVER = ft_server.c minitalk_utils.c minitalk_utils1.c
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):
	$(CC) $(CFLAGS) $(SRCS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER):
	$(CC) $(CFLAGS) $(SRCS_SERVER) -o $(NAME_SERVER)

clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: clean all
