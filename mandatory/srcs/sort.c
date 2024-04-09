/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:28:36 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 02:57:05 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_chunk(stack_a, stack_b);
	tiny_sort(stack_a);
	while (ft_dlstsize(stack_b) > 0)
	{
		set_target(stack_b, stack_a);
		set_cost(stack_b, stack_a);
		init_b(stack_b, stack_a);
		push(stack_b, stack_a, 'A');
	}
	get_min_to_top(stack_a);
}
