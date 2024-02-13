/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 20:39:37 by yjinnouc         ###   ########.fr       */
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
	t_pivot	*top;
	t_pivot	*new_top;
	int		max;

	top = vars->pivot;
	if (top == NULL)
		return (vars->arg_size);
	new_top = vars->pivot->next;
	vars->pivot = new_top;
	max = top->max;
	free(top);
	return (max);
}

void	push_swap_push_loc(t_vars *vars)
{
	t_pivot	*top;

	top = malloc(sizeof(t_pivot));
	if (top == NULL)
		push_swap_error("location alloc error", vars);
	top->max = vars->max;
	top->next = vars->pivot;
	vars->pivot = top;
	return ;
}
