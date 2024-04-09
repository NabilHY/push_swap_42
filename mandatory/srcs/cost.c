/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:35:10 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 02:56:44 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_exception(t_dlist *node, t_dlist *target, int first_size,
		int second_size)
{
	int	cost;
	int	first_distance;
	int	second_distance;

	cost = 0;
	first_distance = 0;
	second_distance = 0;
	if ((node->index < first_size / 2) && (target->index < second_size / 2))
	{
		first_distance = node->index + 1;
		second_distance = target->index + 1;
		if (first_distance == second_distance)
			return (node->index + 1);
	}
	else if ((node->index >= first_size / 2) && (target->index >= second_size
			/ 2))
	{
		first_distance = first_size - node->index - 1;
		second_distance = second_size - target->index - 1;
		if (first_distance == second_distance)
			return (first_size - node->index - 1);
	}
	return (cost);
}

t_dlist	*find_cheapest(t_dlist **stack)
{
	t_dlist	*node;
	t_dlist	*cheapest_node;

	if (!stack || !(*stack))
		return (NULL);
	node = ft_dlstlast(*stack);
	cheapest_node = node;
	if (cheapest_node->cost == 1)
		return (node);
	else
	{
		while (node)
		{
			if (node->cost < cheapest_node->cost)
				cheapest_node = node;
			node = node->prev;
		}
	}
	return (cheapest_node);
}

int	get_cost(t_dlist *node, int size)
{
	int	cost;

	cost = 0;
	if (node->index >= size / 2)
		cost = size - node->index - 1;
	else if (node->index < size / 2)
		cost = node->index + 1;
	return (cost);
}

void	set_cost(t_dlist **first, t_dlist **second)
{
	t_dlist	*node;
	int		cost;
	int		first_size;
	int		second_size;

	first_size = ft_dlstsize(first);
	second_size = ft_dlstsize(second);
	node = ft_dlstfirst(*first);
	while (node)
	{
		cost = find_exception(node, node->target_node, first_size, second_size);
		if (!cost)
		{
			cost += get_cost(node, first_size);
			cost += get_cost(node->target_node, second_size);
		}
		node->cost = cost;
		node = node->next;
	}
}
