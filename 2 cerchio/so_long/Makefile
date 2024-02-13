NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
LINKS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext
LINKS_LINUX = -lX11 -lm -lXext
RM = rm -f

MINILIBX = minilibx/libmlx.a
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SRC = so_long_utils/main \
	so_long_utils/check_map \
	so_long_utils/check_map2 \
	so_long_utils/flood_fill \
	so_long_utils/keypress \
	so_long_utils/print_map \
	so_long_utils/put_image \
	so_long_utils/ft_free

FUNCTIONS:= $(patsubst %, %.c, $(SRC))

OBJ = $(FUNCTIONS:.c=.o)

$(NAME): lib_comp mlx_comp comp_linux

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lib_comp:
	$(MAKE) -C libft/
	$(MAKE) -C ft_printf/
mlx_comp:
	$(MAKE) -C minilibx/

comp_linux: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) $(LINKS_LINUX) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C libft/
	$(MAKE) clean -C ft_printf/

fclean: clean
	$(MAKE) clean -C minilibx/
	$(MAKE) fclean -C libft/
	$(MAKE) fclean -C ft_printf/
	$(RM) $(NAME)

re: fclean all

.PHONY: all lib_comp mlx_comp comp_linux clean fclean re

.SILENT: