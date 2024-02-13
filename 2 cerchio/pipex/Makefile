FLAGS:= -Wall -Werror -Wextra
CC:= cc

NAME:= pipex
BONUS:= pipex_bonus

PATH_GNL:= get_next_line
GNL:= get_next_line.a

PATH_LIBFT:= libft
LIBFT:= libft.a

FUNCTIONS = pipex_utils/pipex.c \
			pipex_utils/ft_execute.c

BONUS_FUNCTIONS = pipex_utils/pipex_bonus.c \
			pipex_utils/ft_execute_bonus.c

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)
BONUS_OBJ:= $(BONUS_FUNCTIONS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_GNL)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_GNL)/$(GNL) -o $(NAME)

bonus: $(BONUS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_GNL)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_GNL)/$(GNL) -o $(BONUS)

clean:
	$(MAKE) clean -C $(PATH_LIBFT)
	$(MAKE) clean -C $(PATH_GNL)
	rm -f $(FUNCTIONS_OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(PATH_LIBFT)
	$(MAKE) fclean -C $(PATH_GNL)
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT:
