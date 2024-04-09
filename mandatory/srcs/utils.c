/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:21:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 02:57:25 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_indexes(t_dlist **stack)
{
	t_dlist	*node;
	int		i;

	i = 0;
	node = ft_dlstfirst(*stack);
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	while (str[i] <= 32)
		i++;
	result = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	in_range(char **args)
{
	long	number;
	int		i;

	i = 0;
	while (args[i])
	{
		number = ft_atol(args[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if (ft_strlen(str) == (unsigned long)i)
		return (1);
	return (0);
}

int	ft_invalid(char **args)
{
	int		i;

	i = 0;
	if (!args || !*args)
		return (1);
	while (args[i])
	{
		if (!*args[i])
			return (1);
		if (ft_check(args[i]))
			return (1);
		i++;
	}
	return (0);
}
