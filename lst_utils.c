/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:28:41 by aalbrech          #+#    #+#             */
/*   Updated: 2024/08/08 18:56:09 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = (*lst);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(struct s_list));
	if (new == NULL)
		return (NULL);
	new->value = content;
	new->next = NULL;
	new->target = NULL;
	new->index = 0;
	new->price = 0;
	new->median = 0;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
}

int	ft_lstlen(t_list *stack_a)
{
	int	len;

	len = 0;
	while (stack_a != NULL)
	{
		len++;
		stack_a = stack_a->next;
	}
	return (len);
}
