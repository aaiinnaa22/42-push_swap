/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:32:45 by aalbrech          #+#    #+#             */
/*   Updated: 2024/09/04 19:51:31 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				price;
	int				median;
	struct s_list	*next;
	struct s_list	*target;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		del_linkedlist(t_list **head);
t_list	*make_stack_a(char **argv);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstlen(t_list *stack_a);
t_list	*find_smallest_val(t_list *stack);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		errorcheck_isnumber(char **argv);
int		errorcheck_doublenumber(t_list *stack_a);
int		error_return(t_list **stack_a, int check);
int		ft_sa_sb(t_list *stack, char recognizer);
int		ft_ss(t_list *stack_a, t_list *stack_b);
int		ft_pa_pb(t_list **stack_src, t_list **stack_dest, char recognizer);
void	ft_ra_rb(t_list **stack, char recognizer);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra_rrb(t_list **stack, char recognizer);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
int		ft_issorted(t_list *stack_a);
void	sort_two(t_list *stack_a);
void	sort_three(t_list **stack_a);
int		sort_five(t_list **stack_a, t_list **stack_b);
int		sort_big(t_list **stack_a, t_list **stack_b);
int		sort_stack(t_list **stack_a);
void	set_target_node(t_list *a, t_list *b);
void	stack_set_index(t_list *stack_a, t_list *stack_b);
void	stack_set_price(t_list *stack_a, t_list *stack_b);
void	set_node_info(t_list *stack_a, t_list *stack_b);
int		push_until_three(t_list **stack_a, t_list **stack_b);
void	stack_set_median(t_list *stack_a, t_list *stack_b);
t_list	*find_cheapest(t_list *stack);
void	both_before_median(t_list **a, t_list **b, t_list *cheapest);
void	both_after_median(t_list **a, t_list **b, t_list *cheapest);
void	until_node_ontop(t_list **stack, t_list *node, char recognizer);

#endif
