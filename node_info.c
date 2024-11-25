/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:10:01 by aalbrech          #+#    #+#             */
/*   Updated: 2024/08/08 19:08:21 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_set_index(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		stack_a->index = i;
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	while (stack_b != NULL)
	{
		stack_b->index = i;
		stack_b = stack_b->next;
		i++;
	}
}

void	stack_set_median(t_list *stack_a, t_list *stack_b)
{
	int	median;

	median = ft_lstlen(stack_a) / 2;
	while (stack_a != NULL)
	{
		if (stack_a->index <= median)
			stack_a->median = 0;
		else if (stack_a->index > median)
			stack_a->median = 1;
		stack_a = stack_a->next;
	}
	median = ft_lstlen(stack_b) / 2;
	while (stack_b != NULL)
	{
		if (stack_b->index <= median)
			stack_b->median = 0;
		else if (stack_b->index > median)
			stack_b->median = 1;
		stack_b = stack_b->next;
	}
}

void	stack_set_price(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(stack_a);
	len_b = ft_lstlen(stack_b);
	while (stack_b != NULL)
	{
		stack_b->price = stack_b->index;
		if (stack_b->median == 1)
			stack_b->price = len_b - stack_b->index;
		if (stack_b->target->median == 0)
			stack_b->price += stack_b->target->index;
		else
			stack_b->price += len_a - stack_b->target->index;
		stack_b = stack_b->next;
	}
}

void	set_target_node(t_list *a, t_list *b)
{
	t_list	*smallest;
	t_list	*temp;

	temp = a;
	smallest = find_smallest_val(a);
	while (b != NULL)
	{
		b->target = NULL;
		a = temp;
		while (a != NULL)
		{
			if (a->value > b->value)
			{
				if (b->target == NULL || a->value < b->target->value)
					b->target = a;
			}
			a = a->next;
		}
		if (b->target == NULL)
			b->target = smallest;
		b = b->next;
	}
}
