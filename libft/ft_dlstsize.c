/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:39:22 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/30 07:28:36 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlstsize(t_dlist **dlist_start)
{
	int		size;
	t_dlist	*node;

	size = 0;
	node = ft_dlstfirst(*dlist_start);
	if (!node)
		return (0);
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
