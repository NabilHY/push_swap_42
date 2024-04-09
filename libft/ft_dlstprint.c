/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:26:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/30 09:24:01 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstprint(t_dlist *current_node, char s)
{
	if (!current_node)
		return ;
	ft_putstr_fd("\n\t| C  STACK  V |\t <==== TAIL ", 1);
	ft_putchar_fd(s, 1);
	ft_putchar_fd('\n', 1);
	current_node = ft_dlstlast(current_node);
	while (current_node)
	{
		ft_putstr_fd("Stack : | ", 1);
		ft_putnbr_fd(current_node->index, 1);
		ft_putstr_fd(" <===> ", 1);
		ft_putnbr_fd(current_node->value, 1);
		ft_putstr_fd(" |   -->", 1);
		if (current_node->target_node)
			ft_putnbr_fd(current_node->cost, 1);
		ft_putstr_fd("\n", 1);
		current_node = current_node->prev;
	}
}
/* if (current_node->target_node) */
