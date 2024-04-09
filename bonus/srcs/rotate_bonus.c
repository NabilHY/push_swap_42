/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:52:06 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 04:37:15 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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
