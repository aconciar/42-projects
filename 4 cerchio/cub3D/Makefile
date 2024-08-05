NAME = cub3D
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
INCLUDE	= -Iinclude -Ilibft
LINKS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext
LINKS_LINUX = -lX11 -lm -lXext
RM = rm -f

MINILIBX_PATH = ./minilibx-linux/
MINILIBX = $(MINILIBX_PATH)libmlx.a
LIBFT = libft/libft.a

SRC = src/main \
	src/main_utils \
	src/parsing/ft_init_map \
	src/parsing/ft_error \
	src/parsing/ft_realloc \
	src/parsing/ft_parsing \
	src/parsing/ft_parse_map \
	src/parsing/ft_check_syntax \
	src/parsing/ft_utils \
	src/parsing/ft_readfile \
	src/ft_load_texture \
	src/ft_hooks_handler \
	src/ft_hooks_handler_utils \
	src/ft_start_game_utils \
	src/ft_move_player_utils \
	src/ft_pixel_put \
	src/ft_minimap \
	src/ft_minimap_utils \
	src/ft_start_game \
	src/ft_animation \
	src/ft_dda \
	src/ft_draw_walls

FUNCTIONS:= $(patsubst %, %.c, $(SRC))

OBJ = $(FUNCTIONS:.c=.o)

$(NAME): lib_comp mlx_comp comp_linux

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

lib_comp:
	$(MAKE) -C libft/
mlx_comp:
	$(MAKE) -C $(MINILIBX_PATH)

comp_linux: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(MINILIBX) $(LINKS_LINUX) -o $(NAME)

bonus: CFLAGS += -DBONUS=1
bonus: re

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C libft/

fclean: clean
	$(MAKE) clean -C $(MINILIBX_PATH)
	$(MAKE) fclean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all lib_comp mlx_comp comp_linux clean fclean re

.SILENT: