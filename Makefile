NAME = so_long

SRCS = src/so_long.c \
      

UTILS = 

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft -Imlx
FSANTIZE = -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

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