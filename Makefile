NAME = so_long
HEADER 		=	so_long.h
CC = gcc
CFLAGS += -Wall -Werror -Wextra -I minilibx
SRC = src/main.c \
		src/map_init.c \
		src/check.c \
		src/check_2.c \
		src/check_3.c \
		src/check_path.c \
		src/check_path_2.c \
		src/parsing.c \
		src/game.c \
		src/game_2.c \
		src/utils.c \
		src/utils_2.c \
		src/utils_3.c \
		src/patrol.c \
		src/patrol_moves.c \
		src/error.c
MLX_FLAGS 	= 	-L./minilibx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Imlx

OBJ = $(SRC:.c=.o)

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) $< -c -o $@ $(INCLUDES)

all: libmlx $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

libmlx:
	$(MAKE) -C ./minilibx/

clean:
	rm -f $(OBJ)
	make clean -C minilibx

fclean: clean
	rm -f $(NAME)

re:	fclean libmlx all

.PHONY: all clean fclean re