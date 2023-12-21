NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lm -lXext -lX11
RM = rm -f
AR = ar rcs

PRINTF := ./ft_printf/libftprintf.a
LIBFT := ./libft/libft.a
MINILIBX := minilibx/libmlx.a

SRCS = main.c /
	check_map.c /
	keypress.c /
	print_map.c /

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): lib_comp mlx_comp lib_comp

lib_comp:
	make -C libft/
mlx_comp:
	make -C minilibx/
printf_comp:
	make -C ft_printf/

comp:
	$(CC) $(CFLAGS) $(MLX) $(SRCS) $(LIBFT) $(PRINTF) $(MINILIBX) 

comp_linux:
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MINILIBX) $(MLX) -o

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C minilibx/
	make -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re