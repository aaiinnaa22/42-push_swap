/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:19:44 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 19:45:26 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	two_helper_make_stack_a(char temp[12], t_list **stack_a)
{
	int		data;
	t_list	*new;

	if (temp[0] == '1' && temp[1] == '\0')
		data = 1;
	else if (temp[0] == '+' && temp[1] == '1' && temp[2] == '\0')
		data = 1;
	else
	{
		data = ft_atoi(temp);
		if (data == 1)
			return (1);
	}
	new = ft_lstnew(data);
	if (!new)
		return (1);
	ft_lstadd_back(stack_a, new);
	return (0);
}

static int	one_helper_make_stack_a(char **argv, t_list **stack_a, int i, int j)
{
	char	temp[12];
	int		y;

	while (argv[i][j] != '\0')
	{
		y = 0;
		ft_bzero(temp, sizeof(temp));
		while (argv[i][j] == ' ' || (argv[i][j] > 8 && argv[i][j] < 14))
			j++;
		if ((argv[i][j] == '-' || argv[i][j] == '+') && y < 12)
			temp[y++] = argv[i][j++];
		while ((argv[i][j] >= '0' && argv[i][j] <= '9') && y < 12)
			temp[y++] = argv[i][j++];
		if (argv[i][j] >= '0' && argv[i][j] <= '9')
			return (1);
		if (temp[0] != '\0')
		{
			if (two_helper_make_stack_a(temp, stack_a) == 1)
				return (1);
		}
		while (argv[i][j] == ' ' || (argv[i][j] > 8 && argv[i][j] < 14))
			j++;
	}
	return (0);
}

t_list	*make_stack_a(char **argv)
{
	int		i;
	int		j;
	int		check;
	t_list	*stack_a;

	stack_a = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		check = one_helper_make_stack_a(argv, &stack_a, i, j);
		if (check == 1)
		{
			del_linkedlist(&stack_a);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}
