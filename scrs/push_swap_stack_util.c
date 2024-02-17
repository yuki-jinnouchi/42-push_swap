/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 00:25:24 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_count_stack(t_stack *head);
int		push_swap_is_sorted(t_stack *head);
int		push_swap_is_empty(t_stack *head);
t_pair	*push_swap_copy_pair(t_pair *pair);

int	push_swap_count_stack(t_stack *head)
{
	t_stack	*temp;
	int		count;

	temp = head->next;
	count = 0;
	while (temp != head)
	{
		temp = temp->next;
		count ++;
	}
	return (count);
}

int	push_swap_is_sorted(t_stack *head)
{
	t_stack	*ptr;

	ptr = head->next;
	while (ptr->next != head)
	{
		if (ptr->number >= ptr->next->number)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

int	push_swap_is_empty(t_stack *head)
{
	if (head->next == head)
		return (TRUE);
	return (FALSE);
}

t_pair	*push_swap_copy_pair(t_pair *pair)
{
	t_pair	*copy_pair;
	t_stack	*copy_head_a;
	t_stack	*copy_head_b;

	copy_pair = (t_pair *) malloc(sizeof(t_pair));
	copy_head_a = push_swap_copy_stack(pair->head_a);
	copy_head_b = push_swap_copy_stack(pair->head_b);
	if (copy_pair == NULL || copy_head_a == NULL || copy_head_b == NULL)
	{
		if (copy_pair != NULL)
			free(copy_pair);
		if (copy_head_a != NULL)
			push_swap_free_stack(copy_head_a);
		if (copy_head_b != NULL)
			push_swap_free_stack(copy_head_b);
		return (NULL);
	}
	copy_pair->head_a = copy_head_a;
	copy_pair->head_b = copy_head_b;
	copy_head_a->opposite = copy_head_b;
	copy_head_b->opposite = copy_head_a;
	return (copy_pair);
}
