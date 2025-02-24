NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -Ift_printf -Iget_next_line

# Define Paths
FT_PRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/

# Source Files (excluding ft_printf since we're linking libftprintf.a)
SRC_FILES = ft_pre_check.c ft_split.c instra_base.c instra_complex.c instra_sample.c \
            mem_mgmt.c push_swap.c rank_index.c s_checker.c sort_more.c cost_mgmt.c \
            $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

BONUS_FILES = ft_pre_check.c ft_split.c instra_base.c instra_complex.c instra_sample.c \
              mem_mgmt.c push_swap_bonus.c ut_bonus.c rank_index.c s_checker.c sort_more.c \
              cost_mgmt.c $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

OBJ = $(SRC_FILES:.c=.o)
BONUS_OBJ = $(BONUS_FILES:.c=.o)

# Compilation Rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure libftprintf.a is built before linking
$(FT_PRINTF_DIR)libftprintf.a:
	make -C $(FT_PRINTF_DIR)

all: $(FT_PRINTF_DIR)libftprintf.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

bonus: $(FT_PRINTF_DIR)libftprintf.a $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(FT_PRINTF_DIR) -lftprintf -o $(BONUS)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
