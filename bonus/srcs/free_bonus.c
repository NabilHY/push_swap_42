/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:22:47 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 04:47:48 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_int_arr(int **arr, int size)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < size - 1)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

t_dlist	*handle_fail(char **arr)
{
	if (arr)
	{
		free_arr(arr);
		*arr = NULL;
	}
	ft_putstr_fd("Error\n", 2);
	return (NULL);
}

void	free_stack(t_dlist **stack)
{
	t_dlist	*node;
	t_dlist	*tmp;

	if (!(*stack))
		return ;
	node = ft_dlstfirst(*stack);
	while (node)
	{
		tmp = node->next;
		free(node);
		node = NULL;
		node = tmp;
	}
	*stack = NULL;
}

int	only_whitespace(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == ' ')
		i++;
	if (i == len)
		return (1);
	return (0);
}
