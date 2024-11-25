/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:51:30 by aalbrech          #+#    #+#             */
/*   Updated: 2024/08/08 19:49:32 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest(t_list *stack)
{
	int		cheapest;
	t_list	*temp;

	cheapest = stack->price;
	temp = stack;
	while (stack != NULL)
	{
		if (stack->price < cheapest)
			cheapest = stack->price;
		stack = stack->next;
	}
	stack = temp;
	while (stack != NULL)
	{
		if (stack->price == cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	both_before_median(t_list **a, t_list **b, t_list *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
	{
		ft_rr(a, b);
		set_node_info(*a, *b);
	}
}

void	both_after_median(t_list **a, t_list **b, t_list *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
	{
		ft_rrr(a, b);
		set_node_info(*a, *b);
	}
}

void	until_node_ontop(t_list **stack, t_list *node, char recognizer)
{
	while (*stack != node)
	{
		if (recognizer == 'a')
		{
			if (node->median == 0)
				ft_ra_rb(stack, 'a');
			else
				ft_rra_rrb(stack, 'a');
		}
		if (recognizer == 'b')
		{
			if (node->median == 0)
				ft_ra_rb(stack, 'b');
			else
				ft_rra_rrb(stack, 'b');
		}
	}
}

t_list	*find_smallest_val(t_list *stack)
{
	int		smallest;
	t_list	*temp;

	temp = stack;
	smallest = stack->value;
	while (temp != NULL)
	{
		if (temp->value < smallest)
			smallest = temp->value;
		temp = temp->next;
	}
	while (stack != NULL)
	{
		if (stack->value == smallest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
