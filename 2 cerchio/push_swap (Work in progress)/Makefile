FLAGS:= -Wall -Werror -Wextra
CC:= cc

NAME:= push_swap

PATH_LIBFT:= libft
LIBFT:= libft.a

PATH_PRINTF:= ft_printf
FT_PRINTF:= libftprintf.a

FUNCTIONS_LIST:= push_swap_utils/main \
				push_swap_utils/ft_print_stack \
				push_swap_utils/ft_lis \
				push_swap_utils/operations \
				push_swap_utils/operations_reverse_rotate \
				push_swap_utils/operations_rotate \
				push_swap_utils/operations_swap \
				push_swap_utils/three_numbers \
				push_swap_utils/five_numbers \
				push_swap_utils/stack_init \
				push_swap_utils/check_input \
				push_swap_utils/check_if_already_in_order \
				push_swap_utils/index_init \
				push_swap_utils/check_efficiency \
				push_swap_utils/check_efficiency_no_save \
				push_swap_utils/sorting \
				push_swap_utils/push_a_to_b \
				push_swap_utils/push_b_to_a \
				push_swap_utils/find_functions \
				push_swap_utils/ft_create_list \
				push_swap_utils/ft_create_node \
				push_swap_utils/ft_free_list \
				push_swap_utils/ft_list_addback \
				push_swap_utils/ft_list_addfront \
				push_swap_utils/ft_list_find_node \
				push_swap_utils/ft_list_last \
				push_swap_utils/ft_list_size \

FUNCTIONS_BONUS:= push_swap_utils/checker/checker \
					push_swap_utils/checker/get_next_line \
					push_swap_utils/get_next_line_utils \

FUNCTIONS:= $(patsubst %, %.c, $(FUNCTIONS_LIST))
BONUS:= $(patsubst %, %.c, $(FUNCTIONS_BONUS))

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)
BONUS_OBJ:= $(FUNCTIONS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_PRINTF)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_PRINTF)/$(FT_PRINTF) -o $(NAME)

bonus: $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_PRINTF)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(BONUS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_PRINTF)/$(FT_PRINTF) -o $(bonus)

clean:
	$(MAKE) clean -C $(PATH_LIBFT)
	$(MAKE) clean -C $(PATH_PRINTF)
	rm -f $(FUNCTIONS_OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(PATH_LIBFT)
	$(MAKE) fclean -C $(PATH_PRINTF)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT: