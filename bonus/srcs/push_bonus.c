/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:59:51 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 02:56:22 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	move_node_to_stack(t_dlist **source_stack, t_dlist **dest_stack)
{
	t_dlist	*last_node;

	if (!source_stack || !(*source_stack))
		return ;
	last_node = ft_dlstlast(*source_stack);
	if (!last_node)
		return ;
	if (last_node->prev)
	{
		last_node->prev->next = NULL;
		last_node->prev = NULL;
	}
	else
		*source_stack = NULL;
	ft_dlstadd_back(dest_stack, last_node);
	update_indexes(source_stack);
	update_indexes(dest_stack);
}
