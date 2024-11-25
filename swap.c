/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:41:56 by aalbrech          #+#    #+#             */
/*   Updated: 2024/08/08 20:11:50 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa_sb(t_list *stack, char recognizer)
{
	t_list	*temp;
	int		first;
	int		second;

	if (ft_lstlen(stack) < 2)
		return (1);
	temp = stack;
	first = temp->value;
	temp = temp->next;
	second = temp->value;
	stack->value = second;
	stack = stack->next;
	stack->value = first;
	if (recognizer == 'a')
		write(1, "sa\n", 3);
	if (recognizer == 'b')
		write(1, "sb\n", 3);
	return (0);
}

int	ft_ss(t_list *stack_a, t_list *stack_b)
{
	if ((ft_lstlen(stack_a) < 2) || (ft_lstlen(stack_b) < 2))
		return (1);
	ft_sa_sb(stack_a, 's');
	ft_sa_sb(stack_b, 's');
	write(1, "ss\n", 3);
	return (0);
}
