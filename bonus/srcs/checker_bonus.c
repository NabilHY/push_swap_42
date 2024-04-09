/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 08:21:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/09 01:13:02 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

char	**handle_set_fail(char **args_arr, char **temp, int i)
{
	args_arr[i] = NULL;
	free_arr(args_arr);
	if (temp)
		free_arr(temp);
	return (NULL);
}

int	ft_checker(t_dlist **stack_a, t_dlist **stack_b)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (line[0] == '\n' || !is_valid(line))
		{
			handle_fail(NULL);
			exit(1);
		}
		else
			do_op(line, stack_a, stack_b);
		free(line);
	}
	if (sorted(stack_a) && (!*stack_b))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_dlist	*a_stack;
	t_dlist	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = parse_args(ac, av);
	if (!a_stack)
		return (0);
	if (ft_checker(&a_stack, &b_stack))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a_stack);
	free_stack(&b_stack);
	return (0);
}
