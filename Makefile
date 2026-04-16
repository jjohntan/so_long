NAME = so_long

SRCS =  src/so_long.c \
		src/parse_map.c \
		src/check_map.c	\
		src/check_map2.c \
		src/put_image.c \
		src/keypress.c \
		src/keypress2.c \
		src/flood_fill.c
      


OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 $(FSANTIZE)
FSANTIZE = -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJS) libft mlx
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -L./mlx_linux -lmlx -L/usr/lib/X11 -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


libft:
	make -C libft

mlx:
	make -C mlx_linux

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean
	make -C mlx_linux clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	make -C mlx_linux fclean 2>/dev/null || true

re: fclean all

.PHONY: all libft clean fclean re
