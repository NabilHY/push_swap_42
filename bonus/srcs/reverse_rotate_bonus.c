/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:52:11 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 04:37:25 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rrotate_nodes(t_dlist *node, t_dlist *prev_node)
{
	int		tmp;
	int		second_tmp;
	t_dlist	*current;
	t_dlist	*current_prev;
	t_dlist	*head;

	current = node;
	head = ft_dlstfirst(node);
	current_prev = prev_node;
	tmp = current->value;
	current->value = head->value;
	current = current_prev;
	current_prev = current_prev->prev;
	while (current)
	{
		second_tmp = current->value;
		current->value = tmp;
		if (!current_prev)
			break ;
		tmp = second_tmp;
		current = current_prev;
		current_prev = current_prev->prev;
	}
	update_indexes(&node);
}

void	rrotate_stack(t_dlist *stack)
{
	if (!stack || (!(stack->next) && !(stack->prev)))
		return ;
	rrotate_nodes(stack, stack->prev);
}

/*
	Our goal is to shift down the whole stack
	1. If stack has no nodes or one node we'll simply return
	2. if stack has two nodes we'll swap their calues and continue
	3. If it has three or more nodes
		we'll start by changing the tail's value to equal the head's
		we'll itterate starting from the penutimate node
		itterating through the previous pointer
		we'll exit once the current node is NULL
		indicating that we've reached the absolute start of our linked list
		at each itteration we'll store the value that we're
*/