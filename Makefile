NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
LIBFT_DIR = ./libft
LIBFT = libft.a
INC_DIR = ./include
SRC_DIR = ./src
MLX_DIR = ./mlx
MLX = libmlx.a
HEADER = $(INC_DIR)/cub3d.h $(INC_DIR)/parse.h
SRCS =	src/cub3d.c src/parse.c src/util.c src/util2.c src/check.c \
		src/map.c src/map_util.c src/debug.c src/texture.c \
		src/execute_error.c src/execute_hook.c src/execute_move.c src/execute.raycasting.c  
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) -j 8
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_DIR)/$(LIBFT) $^ -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

.PHONY: all re clean fclean
