/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:51:28 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 19:58:15 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	check;

	while (ft_lstlen(*stack_a) > 3)
	{
		set_node_info(*stack_a, *stack_b);
		until_node_ontop(stack_a, find_smallest_val(*stack_a), 'a');
		check = ft_pa_pb(stack_a, stack_b, 'b');
		if (check == 1)
			return (1);
	}
	return (0);
}
