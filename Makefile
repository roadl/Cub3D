NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
LIBFT_DIR = ./libft
LIBFT = libft.a
INC_DIR = ./include
SRC_DIR = ./src
HEADER = cub3d.h \
		execute.h
SRCS =	execute_error.c \
		execute_hook.c	\
		execute_main.c	\
		execute_move.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
HEADER := $(addprefix $(INC_DIR)/, $(HEADER))
LIBFT := $(addprefix $(LIBFT_DIR)/, $(LIBFT))
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
