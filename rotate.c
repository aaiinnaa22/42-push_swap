/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:56:53 by aalbrech          #+#    #+#             */
/*   Updated: 2024/08/08 20:11:59 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rb(t_list **stack, char recognizer)
{
	t_list	*temp;
	t_list	*new_head;

	temp = (*stack);
	new_head = temp->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = new_head;
	if (recognizer == 'a')
		write(1, "ra\n", 3);
	if (recognizer == 'b')
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra_rb(stack_a, 'r');
	ft_ra_rb(stack_b, 'r');
	write(1, "rr\n", 3);
}
