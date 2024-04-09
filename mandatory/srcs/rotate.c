/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:52:06 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 05:08:34 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_values(t_dlist *node_1, t_dlist *node_2)
{
	int	temp;

	temp = node_1->value;
	node_1->value = node_2->value;
	node_2->value = temp;
}

void	rotate_nodes(t_dlist *node, t_dlist *next_node)
{
	int		tmp;
	int		second_tmp;
	t_dlist	*current;
	t_dlist	*current_next;

	current = node;
	current_next = next_node;
	tmp = current->value;
	current->value = ft_dlstlast(node)->value;
	current = current_next;
	current_next = current_next->next;
	while (current)
	{
		second_tmp = current->value;
		current->value = tmp;
		if (!current_next)
			break ;
		tmp = second_tmp;
		current = current_next;
		current_next = current_next->next;
	}
	update_indexes(&node);
}

void	rotate_stack(t_dlist *stack)
{
	if (!stack || (!(stack->next) && !(stack->prev)))
		return ;
	rotate_nodes(stack, stack->next);
}

void	rotate(t_dlist **first_stack, t_dlist **second_stack)
{
	if (!first_stack && !second_stack)
		return ;
	if (first_stack && !second_stack)
	{
		rotate_stack(ft_dlstfirst(*first_stack));
		ft_putstr_fd("ra\n", 1);
	}
	else if (!first_stack && second_stack)
	{
		rotate_stack(ft_dlstfirst(*second_stack));
		ft_putstr_fd("rb\n", 1);
	}
	else
	{
		rotate_stack(ft_dlstfirst(*first_stack));
		rotate_stack(ft_dlstfirst(*second_stack));
		ft_putstr_fd("rr\n", 1);
	}
}
