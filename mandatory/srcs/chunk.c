/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:34:18 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 05:18:18 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_average(t_dlist **stack)
{
	int		i;
	int		sum;
	t_dlist	*node;

	i = 0;
	sum = 0;
	node = ft_dlstfirst(*stack);
	while (node)
	{
		sum += node->value;
		i++;
		node = node->next;
	}
	return (sum / i);
}

void	ft_chunk(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*node;
	int		average;

	average = get_average(stack_a);
	while (ft_dlstsize(stack_a) > 3)
	{
		node = ft_dlstlast(*stack_a);
		if (node->value >= average)
			push(stack_a, stack_b, 'B');
		else
		{
			push(stack_a, stack_b, 'B');
			rotate(NULL, stack_b);
		}
	}
}
