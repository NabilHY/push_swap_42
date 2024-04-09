/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:19:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 05:16:58 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

t_dlist	*parse_args(int ac, char **av);
int		check_args(char **arr_of_args);
void	free_arr(char **arr);
int		check_repetition(char **arr_of_args);
void	push(t_dlist **first_stack, t_dlist **second_stack, char stack);
void	rotate(t_dlist **first_stack, t_dlist **second_stack);
void	rrotate(t_dlist **first_stack, t_dlist **second_stack);
void	swap(t_dlist **first_stack, t_dlist **second_stack);
void	update_indexes(t_dlist **stack);
void	push_swap(t_dlist **stack_a, t_dlist **stack_b);
void	fill_arr(t_dlist **stack, int *arr);
void	fill_arr_dif(t_dlist **stack, t_dlist *node, int *arr);
int		min_value(t_dlist **stack);
void	tiny_sort(t_dlist **stack);
void	free_stack(t_dlist **stack);
void	free_arr(char **arr);
t_dlist	*handle_fail(char **arr);
void	free_stack(t_dlist **stack);
int		is_sorted(t_dlist **stack);
void	set_target(t_dlist **first, t_dlist **second);
void	set_cost(t_dlist **first, t_dlist **second);
void	sort(t_dlist **stack_a, t_dlist **stack_b);
t_dlist	*find_cheapest(t_dlist **stack);
void	node_top(t_dlist *node, t_dlist **stack, int size, char c);
void	init_b(t_dlist **first_stack, t_dlist **second_stack);
void	get_min_to_top(t_dlist **stack_a);
void	ft_chunk(t_dlist **stack_a, t_dlist **stack_b);
void	free_int_arr(int **arr, int size);
int		*arr_alloc(int size);
int		in_range(char **args);
long	ft_atol(char *str);
int		in_range(char **args);
int		ft_invalid(char **args);
void	move_node_to_stack(t_dlist **source_stack, t_dlist **dest_stack);
void	rotate_stack(t_dlist *stack);
void	rrotate_stack(t_dlist *stack);
void	swap_stack(t_dlist *tail);
int		only_whitespace(char *str);
char	**handle_set_fail(char **args_arr, char **temp, int i);
#endif