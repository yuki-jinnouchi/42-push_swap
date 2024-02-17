/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 19:09:24 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_valid_input(t_stack *head, int n);
int		push_swap_2stack_compare_wrap(t_stack *head_i, t_stack *head_j);
int		push_swap_pairs_compare_order(t_pair *pair_i, t_pair *pair_j);
int		push_swap_stack_compare_order(t_stack *head_i, t_stack *head_j);
int		push_swap_is_pair_completed(t_pair *pair);

/*valid not 0 and non duplicated (ignore even if it's outside of MIN-MAX_INT)*/
int	push_swap_valid_input(t_stack *head, int n)
{
	t_stack	*temp;

	if (n == 0)
		return (FALSE);
	temp = head->next;
	while (temp != head)
	{
		if (temp->number == n)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

/*
int	push_swap_2stack_compare_wrap(t_stack *head_i, t_stack *head_j)
{
	if (push_swap_stack_compare(head_i, head_j) == FALSE)
		return (FALSE);
	if (push_swap_stack_compare(head_i->opposite, head_j->opposite) == FALSE)
		return (FALSE);
	return (TRUE);
}
*/

int	push_swap_pairs_compare_order(t_pair *pair_i, t_pair *pair_j)
{
	if (push_swap_stack_compare_order(pair_i->head_a, pair_j->head_a) == FALSE)
		return (FALSE);
	if (push_swap_stack_compare_order(pair_i->head_b, pair_j->head_b) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	push_swap_stack_compare_order(t_stack *head_i, t_stack *head_j)
{
	t_stack	*temp_i;
	t_stack	*temp_j;

	temp_i = head_i->next;
	temp_j = head_j->next;
	while (temp_i != head_i)
	{
		if (temp_i->order != temp_j->order)
			return (FALSE);
		temp_i = temp_i->next;
		temp_j = temp_j->next;
	}
	if (temp_j != head_j)
		return (FALSE);
	return (TRUE);
}

int	push_swap_is_pair_completed(t_pair *pair)
{
	if (push_swap_is_sorted(pair->head_a) == FALSE)
		return (FALSE);
	if (push_swap_is_empty(pair->head_b) == FALSE)
		return (FALSE);
	return (TRUE);
}
