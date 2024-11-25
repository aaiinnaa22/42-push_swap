/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:18:50 by aalbrech          #+#    #+#             */
/*   Updated: 2024/08/08 20:12:14 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	helper_errorcheck_isnumber(char argv, char next_argv)
{
	if (argv == ' ')
		return (0);
	if ((argv == '+' || argv == '-') && (next_argv >= '0' && next_argv <= '9'))
		return (0);
	if (argv >= '0' && argv <= '9')
		return (0);
	else
		return (1);
}

int	errorcheck_isnumber(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (helper_errorcheck_isnumber(argv[i][j], argv[i][j + 1]) == 1)
				return (1);
			j++;
		}
		i++;
	}		
	return (0);
}

int	errorcheck_doublenumber(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a != NULL)
	{
		temp = stack_a->next;
		while (temp != NULL)
		{
			if (temp->value == stack_a->value)
				return (1);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}
