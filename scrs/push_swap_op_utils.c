/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/12 23:30:51 by yjinnouc         ###   ########.fr       */
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

t_stack	*push_swap_pop(t_stack *head)
{
	t_stack	*top;
	t_stack	*new_top;

	top = head->next;
	if (top == head)
		return (NULL);
	new_top = head->next->next;
	new_top->prev = head;
	head->next = new_top;
	return (top);
}

void	push_swap_push(t_stack *head, t_stack *new_top)
{
	t_stack	*top;

	top = head->next;
	top->prev = new_top;
	head->next = new_top;
	new_top->next = top;
	new_top->prev = head;
	return ;
}

int	push_swap_pop_loc(t_vars *vars)
{
	t_location	*top;
	t_location	*new_top;
	int			max;

	top = vars->pivot;
	if (top == NULL)
		return (0);
	new_top = vars->pivot->next;
	vars->pivot = new_top;
	max = top->median;
	free(top);
	return (max);
}

void	push_swap_push_loc(int median, t_vars *vars)
{
	t_location	*top;

	top = malloc(sizeof(t_location));
	if (top == NULL)
		push_swap_error("location alloc error", vars);
	// top->ptr = new_top;
	top->median = median;
	top->min = vars->min;
	top->max = vars->max;
	top->next = vars->pivot;
	vars->pivot = top;
	return ;
}
