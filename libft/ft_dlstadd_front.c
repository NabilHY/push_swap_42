/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:26:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/04 12:47:29 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*head;

	if (!dlst || !new)
		return ;
	if (!*dlst)
	{
		*dlst = new;
		return ;
	}
	head = ft_dlstfirst(*dlst);
	new->next = head;
	new->prev = NULL;
	head->prev = new;
	*dlst = new;
}
