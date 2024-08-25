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
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft -Imlx
FSANTIZE = -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -lmlx -framework OpenGL -framework Appkit -o $(NAME)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


libft:
	make -C libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re