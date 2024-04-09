/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:18:39 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 04:09:46 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../libft/libft.h"

int	main(int ac, char **av)
{
	t_dlist	*a_stack;
	t_dlist	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	a_stack = parse_args(ac, av);
	if (!a_stack)
		return (0);
	push_swap(&a_stack, &b_stack);
	free_stack(&a_stack);
	return (0);
}

/*
Methods :
	Double Linked List Methods
		-> ft_dlstprint(node, char 'A' OR 'B')  => print stack
		-> t_dlist	*ft_dlstindex(t_dlist **stack, int n) => return node at
			with index n

			PUSH METHODS
	push_to_stacks(**stack1, NULL)  => pa
	push_to_stacks(NULL, **stack2)  => pb

			SWAP METHODS
	swap_stacks(**stack1, NULL) => sa
	swap_stacks(NULL, **stack2) => sb
	swap_stacks(**stack1, **stack2) => ss

			ROTATION METHODS
	rotate_stacks(**stack1, NULL)  => ra
	rotate_stacks(NULL, **stack2)  => rb
	rotate_stacks(**stack1, **stack2)  => rr
 |
Stack : | 3 <===> -29 |
			REVERSE ROTATION METHODS
	rrotate_stacks(**stack1, NULL)  => rra
	rrotate_stacks(NULL, **stack2)  => rrb
	rrotate_stacks(**stack1, **stack2)  => rrr

			SORT A STACK OF THREE NODES
	==> Sort Stack A
			sort_stack_of_three(&a_stack, 'A')
	==> Sort Stack B
			sort_stack_of_three(&b_stack, 'B')
*/