/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:12:27 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 19:53:36 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			plusminus;
	long int	res;

	i = 0;
	plusminus = 1;
	res = 0;
	if (str[i] == '+' && (str[i + 1] > 47 && str[i + 1] < 58))
		i++;
	if (str[i] == '-' && (str[i + 1] > 47 && str[i + 1] < 58))
	{
		plusminus = plusminus * (-1);
		i++;
	}
	if (str[i] == '0' && str[i + 1] == '0')
		return (1);
	while (str[i] > 47 && str[i] < 58)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (((res * plusminus) > 2147483647) || ((res * plusminus) < -2147483648))
		return (1);
	return (res * plusminus);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n != 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	del_linkedlist(t_list **head)
{
	t_list	*temp;
	t_list	*next;

	temp = (*head);
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*head = NULL;
	return (1);
}
