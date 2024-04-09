/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:22:39 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 02:57:20 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dlist	*closest_node(t_dlist *node, t_dlist **stack)
{
	t_dlist	*target_node;
	int		diff;
	int		*arr;
	int		i;

	i = 0;
	target_node = NULL;
	arr = arr_alloc(ft_dlstsize(stack));
	if (!arr)
		return (NULL);
	fill_arr(stack, arr);
	diff = __INT_MAX__;
	while (i < ft_dlstsize(stack))
	{
		if ((arr[i] > node->value) && (arr[i] < diff))
		{
			diff = arr[i];
			target_node = ft_dlstindex(stack, i);
		}
		i++;
	}
	if (!target_node)
		target_node = ft_dlstindex(stack, min_value(stack));
	free(arr);
	return (target_node);
}

void	set_target(t_dlist **first, t_dlist **second)
{
	t_dlist	*node;

	node = ft_dlstfirst(*first);
	while (node)
	{
		node->target_node = closest_node(node, second);
		node = node->next;
	}
}
