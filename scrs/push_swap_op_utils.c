/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/11 02:20:43 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
typedef struct s_tack
{
	int				*number;
	int				*order;
	struct s_tack	*next;
	struct s_tack	*prev;
}	t_stack;
*/

t_stack	*push_swap_pop(t_stack *stack)
{
	t_stack	*prev;
	t_stack	*next;

	prev = stack->prev;
	if (prev == stack)
		return (NULL);
	next = stack->next;
	prev->next = next;
	next->prev = prev;
	return (prev);
}

void	push_swap_push(t_stack *stack, t_stack *target)
{
	t_stack	*prev;

	prev = stack->prev;
	prev->next = target;
	target->prev = prev;
	target->next = stack;
	stack->prev = target;
	return ;
}

int	push_swap_is_sorted_stack(t_stack *head)
{
	t_stack	*ptr;
	int		temp;

	ptr = head->prev;
	temp = ptr->number;
	while (ptr->number != 0)
	{
		if (temp < ptr->prev->number)
			return (FALSE);
		ptr = ptr->prev;
	}
	return (TRUE);
}

int	push_swap_is_empty_stack(t_stack *head)
{
	if (head->prev == head)
		return (TRUE);
	return (FALSE);
}
