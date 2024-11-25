/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:10:43 by aalbrech          #+#    #+#             */
/*   Updated: 2024/08/08 20:14:32 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rra_rrb(t_list **stack, char recognizer)
{
	t_list	*temp;
	t_list	*new_last;
	t_list	*new_head;

	temp = (*stack);
	while (temp->next->next != NULL)
		temp = temp->next;
	new_last = temp;
	new_head = temp->next;
	new_last->next = NULL;
	new_head->next = (*stack);
	(*stack) = new_head;
	if (recognizer == 'a')
		write(1, "rra\n", 4);
	if (recognizer == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra_rrb(stack_a, 'r');
	ft_rra_rrb(stack_b, 'r');
	write(1, "rrr\n", 4);
}
