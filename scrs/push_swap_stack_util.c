/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 21:47:35 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_count_stack(t_stack *head);
int		push_swap_is_sorted(t_stack *head);
int		push_swap_is_empty(t_stack *head);

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
