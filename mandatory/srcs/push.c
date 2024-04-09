/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:59:51 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 05:08:40 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// we need to push

#include "../push_swap.h"

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

void	push(t_dlist **first_stack, t_dlist **second_stack, char stack)
{
	if (!first_stack || !second_stack || !*first_stack)
		return ;
	if (stack == 'A')
		ft_putstr_fd("pa\n", 1);
	else if (stack == 'B')
		ft_putstr_fd("pb\n", 1);
	move_node_to_stack(first_stack, second_stack);
}

/*
	- if second_stack is null, change it to
	point to the pushed value address
	- change the pushed value prev and next accordingly (next
		-> to the head of the list you want
	to push to,
		prev will always be NULL)
		change the prev of the second value in the stack to point
	to the first
	- profit $$$$$

*/

/*
we'll be pushing the tail of first stack towards the second stack to be it's tail

SCENARIOS For both stacks

1. stack 1 is empty (ft_dlstlast return NULL)
	-> Do nothing
2. stack 1 has one or more
nodes in it (stack1->tail->previous)
	-> stack 1 has one node
		-> Goal should be to capture
		then return the whole node and free_the whole stack 1
			-> Capture first stack's
			tail ft_dlstlast() in a variale and update its values
				-> It's index value
				should be the length of stack 2
				-> Its prev value
				should be the address of stack 2 tail
				-> Its next value
				should be NULL
					-> After Node
					is captured we'll free the old node (F_S_T->prev)
					-> Update F_S_T->prev
					 to point to null
			-> if stack1->tail->previous is NULL ()
				-> Clear The whole stack
		-> function would return that one
		node and should free all the memory that was previously
		allocated for stack 1
	-> stack 1 has more than one
		-> Goal is The capture the tail then
		Update the Node before the old tail
			-> change tail address  (stack1->tail->prev) to NULL
			-> Free The memory allocated for stack 1 old tail

<===>

Now that we have captured the Node
we have to manage stack 2 side os things

1. stack 2 is empty
	-> we'll simply take the captured node
	and insert it using ft_dlstadd_back
2. stack 2 has one or more nodes in it
	->
*/