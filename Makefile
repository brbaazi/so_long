
NAME = so_long

SRC_DIR = src
LIBFT_DIR = libft
MLX_DIR = /usr/include/minilibx-linux
GNL_DIR = get_next_line
FT_PRINTF_DIR = ft_printf
INC_DIR = includes

SRCS = $(SRC_DIR)/so_long.c \
       $(SRC_DIR)/init.c \
	   $(SRC_DIR)/setup_hooks.c\
       $(SRC_DIR)/parser_map.c \
       $(SRC_DIR)/parser_utils.c \
       $(SRC_DIR)/parsing.c \
       $(SRC_DIR)/path_checker.c \
       $(SRC_DIR)/render.c \
       $(SRC_DIR)/events.c \
       $(GNL_DIR)/get_next_line.c \
       $(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(FT_PRINTF_DIR)
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(FT_PRINTF)
	$(CC) $(OBJS) $(LIBFT) $(MLX) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re