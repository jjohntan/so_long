NAME = so_long

SRCS = 	src/so_long.c \
		src/read_map.c \
		src/check_map.c
      

OBJS = $(SRCS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft -Imlx #$(FSANTIZE) -g3
FSANTIZE = -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX_LIBRARY) -Llibft -lft -o $(NAME)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


ifeq ($(shell uname), Linux)
MINILIBX = minilibx-linux/
MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
MINILIBX = minilibx/
MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit
endif

a:
	echo $(MINILIBX_LIBRARY)

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