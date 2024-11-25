/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:11:10 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 19:56:52 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_node_info(t_list *stack_a, t_list *stack_b)
{
	set_target_node(stack_a, stack_b);
	stack_set_index(stack_a, stack_b);
	stack_set_price(stack_a, stack_b);
	stack_set_median(stack_a, stack_b);
}

static int	sort_round(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;
	int		check;

	cheapest = find_cheapest(*stack_b);
	if (cheapest->median == 0 && cheapest->target->median == 0)
		both_before_median(stack_a, stack_b, cheapest);
	else if (cheapest->median == 1 && cheapest->target->median == 1)
		both_after_median(stack_a, stack_b, cheapest);
	until_node_ontop(stack_b, cheapest, 'b');
	until_node_ontop(stack_a, cheapest->target, 'a');
	check = ft_pa_pb(stack_b, stack_a, 'a');
	if (check == 1)
		return (1);
	return (0);
}

int	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	check;

	check = push_until_three(stack_a, stack_b);
	if (check == 1)
		return (1);
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		set_node_info(*stack_a, *stack_b);
		check = sort_round(stack_a, stack_b);
		if (check == 1)
			return (1);
	}
	until_node_ontop(stack_a, find_smallest_val(*stack_a), 'a');
	return (0);
}
