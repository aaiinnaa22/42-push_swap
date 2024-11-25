/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:12:08 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 20:15:08 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_list **stack_a)
{
	t_list	*stack_b;

	if (ft_lstlen(*stack_a) == 2)
		sort_two(*stack_a);
	if (ft_lstlen(*stack_a) == 3)
		sort_three(stack_a);
	else
	{
		stack_b = NULL;
		if (ft_lstlen(*stack_a) == 5)
		{
			if (sort_five(stack_a, &stack_b) == 1)
				return (del_linkedlist(&stack_b));
		}
		if (sort_big(stack_a, &stack_b) == 1)
			return (del_linkedlist(&stack_b));
		del_linkedlist(&stack_b);
	}
	del_linkedlist(stack_a);
	return (0);
}
