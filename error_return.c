/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:12:44 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 18:56:29 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_return(t_list **stack_a, int check)
{
	if (check == 1)
		del_linkedlist(stack_a);
	write(2, "Error\n", 6);
	return (0);
}
