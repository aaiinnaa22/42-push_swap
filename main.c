/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:05:45 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 20:23:28 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (errorcheck_isnumber(argv) == 1)
		return (error_return(&stack_a, 0));
	stack_a = make_stack_a(argv);
	if (stack_a == NULL)
		return (error_return(&stack_a, 1));
	if (errorcheck_doublenumber(stack_a) == 1)
		return (error_return(&stack_a, 1));
	if (ft_issorted(stack_a) == 0)
	{
		del_linkedlist(&stack_a);
		return (0);
	}
	if (sort_stack(&stack_a) == 1)
		return (error_return(&stack_a, 1));
	return (0);
}
