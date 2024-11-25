/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:11:26 by aalbrech          #+#    #+#             */
/*   Updated: 2024/08/08 17:47:41 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	t_list	**temp;

	while (1)
	{
		if (ft_issorted(*stack_a) == 0)
			break ;
		temp = stack_a;
		if ((*temp)->value > (*temp)->next->value)
			ft_sa_sb(*temp, 'a');
		else
			ft_rra_rrb(temp, 'a');
	}
}
