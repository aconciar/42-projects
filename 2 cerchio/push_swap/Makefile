FLAGS:= -Wall -Werror -Wextra
CC:= cc

NAME:= push_swap
BONUS_NAME:= checker

PATH_GNL:= get_next_line
GNL:= get_next_line.a

PATH_LIBFT:= libft
LIBFT:= libft.a

PATH_PRINTF:= ft_printf
FT_PRINTF:= libftprintf.a

FUNCTIONS = ./push_swap_utils/main.c \
	./push_swap_utils/check_efficiency.c \
	./push_swap_utils/check_efficiency_no_save.c \
	./push_swap_utils/check_if_already_in_order.c \
	./push_swap_utils/check_input.c \
	./push_swap_utils/find_functions.c \
	./push_swap_utils/five_numbers.c \
	./push_swap_utils/ft_create_list.c \
	./push_swap_utils/ft_create_node.c \
	./push_swap_utils/ft_free_list.c \
	./push_swap_utils/ft_list_addback.c \
	./push_swap_utils/ft_list_addfront.c \
	./push_swap_utils/ft_list_find_node.c \
	./push_swap_utils/ft_list_last.c \
	./push_swap_utils/ft_list_size.c \
	./push_swap_utils/ft_print_stack.c \
	./push_swap_utils/index_init.c \
	./push_swap_utils/operations.c \
	./push_swap_utils/operations_reverse_rotate.c \
	./push_swap_utils/operations_rotate.c \
	./push_swap_utils/operations_swap.c \
	./push_swap_utils/push_a_to_b.c \
	./push_swap_utils/push_b_to_a.c \
	./push_swap_utils/sorting.c \
	./push_swap_utils/stack_init.c \
	./push_swap_utils/three_numbers.c

FUNCTIONS_BONUS = ./push_swap_utils/checker/checker.c \
	./push_swap_utils/checker/error_functions.c \
	./push_swap_utils/check_efficiency.c \
	./push_swap_utils/check_efficiency_no_save.c \
	./push_swap_utils/check_if_already_in_order.c \
	./push_swap_utils/check_input.c \
	./push_swap_utils/find_functions.c \
	./push_swap_utils/five_numbers.c \
	./push_swap_utils/ft_create_list.c \
	./push_swap_utils/ft_create_node.c \
	./push_swap_utils/ft_free_list.c \
	./push_swap_utils/ft_list_addback.c \
	./push_swap_utils/ft_list_addfront.c \
	./push_swap_utils/ft_list_find_node.c \
	./push_swap_utils/ft_list_last.c \
	./push_swap_utils/ft_list_size.c \
	./push_swap_utils/ft_print_stack.c \
	./push_swap_utils/index_init.c \
	./push_swap_utils/operations.c \
	./push_swap_utils/operations_reverse_rotate.c \
	./push_swap_utils/operations_rotate.c \
	./push_swap_utils/operations_swap.c \
	./push_swap_utils/push_a_to_b.c \
	./push_swap_utils/push_b_to_a.c \
	./push_swap_utils/sorting.c \
	./push_swap_utils/stack_init.c \
	./push_swap_utils/three_numbers.c

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)
BONUS_OBJ:= $(FUNCTIONS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_PRINTF)
	$(MAKE) -C $(PATH_GNL)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_PRINTF)/$(FT_PRINTF) -o $(NAME)

bonus: $(NAME) $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_PRINTF)/$(FT_PRINTF) $(PATH_GNL)/$(GNL) -o $(BONUS_NAME)

clean:
	$(MAKE) clean -C $(PATH_LIBFT)
	$(MAKE) clean -C $(PATH_PRINTF)
	$(MAKE) clean -C $(PATH_GNL)
	rm -f $(FUNCTIONS_OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(PATH_LIBFT)
	$(MAKE) fclean -C $(PATH_PRINTF)
	$(MAKE) fclean -C $(PATH_GNL)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT:
