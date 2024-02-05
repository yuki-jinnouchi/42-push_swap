/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/05 06:57:21 by yjinnouc         ###   ########.fr       */
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
	t_stack *prev;
	t_stack *next;

	prev = stack -> prev;
	if(prev == stack)
		return (NULL);
	next = stack -> next;
	prev -> next = next;
	next ->	prev = prev;
	return (prev);
}

void	push_swap_push(t_stack *stack, t_stack *target)
{
	t_stack *prev;

	prev = stack -> prev;
	prev -> next = target;
	target -> prev = prev;
	target -> next = stack;
	stack -> prev = target;
	return ;
}