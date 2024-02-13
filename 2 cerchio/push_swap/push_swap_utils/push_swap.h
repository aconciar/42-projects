/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:39 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/12 17:03:55 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_lis
{
	int						length;
	int						index;
	int						lis_index;
	int						sub_sequence;
	bool					has_index;
	struct s_lis			*next;
}				t_lis;

typedef struct s_operator
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}				t_operator;

typedef struct s_stack
{
	int						value;
	int						index;
	int						has_index;
	int						chunk;
	int						push;
	struct s_stack			*next;
	struct s_stack			*prev;
}				t_stack;

void	ft_print_stack(t_stack *stack);
t_stack	*ft_create_node(int value);
t_stack	*ft_create_list(int argc, char **argv);
t_stack	*ft_list_last(t_stack *list);
void	ft_free_list(t_stack *list);
void	ft_list_addfront(t_stack **list, t_stack *new);
void	ft_list_addback(t_stack **list, t_stack *new);
t_stack	*ft_list_find_node(t_stack *list, int value);
int		ft_list_size(t_stack *list);
int		check_input(char *str, int y);
int		stack_init(int argc, char *argv[], t_stack **stack_a);
int		find_biggest_length(t_lis *lis, int size);
t_lis	*find_biggest_length_node(t_lis *lis, int size, int length_to_search);
void	pa(t_stack **stack, t_stack **node, int i);
void	pb(t_stack **stack, t_stack **node, int i);
void	sa(t_stack **stack, int i);
void	sb(t_stack **stack, int i);
void	ss(t_stack **stack_a, t_stack **stack_b, int i);
void	ra(t_stack **stack, int i);
void	rb(t_stack **stack, int i);
void	rr(t_stack **stack_a, t_stack **stack_b, int i);
void	rbb(t_stack **stack, int i);
void	rra(t_stack **stack, int i);
void	rrb(t_stack **stack, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b, int i);;
int		check_order(t_stack *stack);
int		free_mat(char **mat, int i);
char	*ft_strjoinps(char *left_str, char *buff);
void	two_numbers_a(t_stack **stack_a);
void	three_numbers_a(t_stack **stack_a);
void	three_numbers_b(t_stack **stack_b);
void	five_numbers(t_stack **stack_a, t_stack **stack_b);
void	sorting(t_stack **stack_a, t_stack **stack_b);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, int c, int m);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	ft_smallest_on_top(t_stack **stack);
void	index_init(t_stack **stack, int c, int t);
void	check_efficiency(t_stack *stack_a, t_stack *stack_b, t_operator *value);
int		efficiencycounter_nosave(t_stack *stack_a, t_stack *stack_b, int index);
void	efficiency_counter(t_stack *a, t_stack *b, int index, t_operator **val);
int		find_biggest(t_stack *stack);
int		find_smallest(t_stack *stack);
int		find_biggest_before_index(t_stack *stack, int index);
int		find_smallest_after_index(t_stack *stack, int index);
int		find_value(t_stack *stack, int value);
int		find_eff(t_stack *stack, int index);
int		find_push(t_stack *stack, int chunk1, int chunk2);
void	ft_error(t_stack **stack_a, t_stack **stack_b, char *line);
void	ft_ko(t_stack **stack_a, t_stack **stack_b, char *line);

#endif
