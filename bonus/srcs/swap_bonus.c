/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 05:04:06 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 05:06:22 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	swap_nodes(t_dlist *tail, t_dlist *penultimate)
{
	if (penultimate->prev == NULL)
	{
		penultimate->prev = tail;
		penultimate->next = NULL;
		tail->next = penultimate;
		tail->prev = NULL;
	}
	else
	{
		penultimate->prev->next = tail;
		tail->prev = penultimate->prev;
		tail->next = penultimate;
		penultimate->next = NULL;
		penultimate->prev = tail;
	}
	update_indexes(&tail);
}

void	swap_stack(t_dlist *tail)
{
	if (!tail)
		return ;
	else if (!(tail->next) && !(tail->prev))
		return ;
	else if (tail->prev)
		swap_nodes(tail, tail->prev);
}
