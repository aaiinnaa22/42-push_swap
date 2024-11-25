/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:14:23 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 19:45:54 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa_pb(t_list **stack_src, t_list **stack_dest, char recognizer)
{
	t_list	*new;
	int		data;
	t_list	*temp;

	if (stack_src == NULL)
		return (1);
	data = (*stack_src)->value;
	new = ft_lstnew(data);
	if (!new)
		return (1);
	ft_lstadd_front(stack_dest, new);
	temp = (*stack_src);
	(*stack_src)->value = 0;
	*stack_src = (*stack_src)->next;
	free(temp);
	if (recognizer == 'a')
		write(1, "pa\n", 3);
	if (recognizer == 'b')
		write(1, "pb\n", 3);
	return (0);
}

int	push_until_three(t_list **stack_a, t_list **stack_b)
{
	int	check;

	while (ft_lstlen(*stack_a) > 3)
	{
		check = ft_pa_pb(stack_a, stack_b, 'b');
		if (check == 1)
			return (1);
	}
	return (0);
}
