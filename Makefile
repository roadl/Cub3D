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
HEADER = $(INC_DIR)/cub3d.h
SRCS =	src/cub3d.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) -j 8
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT) $^ -o $(NAME)

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
