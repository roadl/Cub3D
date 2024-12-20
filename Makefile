# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yojin <yojin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 13:02:18 by yojin             #+#    #+#              #
#    Updated: 2024/12/20 13:33:10 by yojin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = ./libft
LIBFT = libft.a
INC_DIR = ./include
SRC_DIR = ./src
MLX_DIR = ./mlx
MLX = libmlx.a
HEADER = $(INC_DIR)/cub3d.h
SRCS =	src/cub3d.c
OBJS = $(SRCS:.c=.o)
NAME = fdf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) -j 8
	make -C $(MLX_DIR) -j 8
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $(NAME) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

re: fclean all

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

.PHONY: all re clean fclean