/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_base_rx.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:03:01 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 05:56:40 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_ra(t_pair *stack, t_vars *vars);
void	push_swap_rb(t_pair *stack, t_vars *vars);
void	push_swap_rr(t_pair *stack, t_vars *vars);

// /*ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.*/
// /*rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.*/
// /*rr : ra and rb at the same time*/

void	push_swap_ra(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_a) > 1)
	{
		temp = push_swap_pop(stack->head_a);
		push_swap_push(stack->head_a->prev, temp);
	}
	if (vars != NULL)
		push_swap_add_step(6, "ra\n", vars);
	return ;
}

void	push_swap_rb(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_b) > 1)
	{
		temp = push_swap_pop(stack->head_b);
		push_swap_push(stack->head_b->prev, temp);
	}
	if (vars != NULL)
		push_swap_add_step(7, "rb\n", vars);
	return ;
}

void	push_swap_rr(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_a) > 1)
	{
		temp = push_swap_pop(stack->head_a);
		push_swap_push(stack->head_a->prev, temp);
	}
	if (push_swap_count_stack(stack->head_b) > 1)
	{
		temp = push_swap_pop(stack->head_b);
		push_swap_push(stack->head_b->prev, temp);
	}
	if (vars != NULL)
		push_swap_add_step(8, "rr\n", vars);
	return ;
}
