/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_base_rrx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:03:01 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 12:40:56 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_rra(t_pair *stack, t_vars *vars);
void	push_swap_rrb(t_pair *stack, t_vars *vars);
void	push_swap_rrr(t_pair *stack, t_vars *vars);

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
/*rrr : rra and rrb at the same time.*/

void	push_swap_rra(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;
	// push_swap_print_stack_order(stack->head_a);
	if (push_swap_count_stack(stack->head_a) > 1)
	{
		temp = push_swap_pop(stack->head_a->prev->prev);
		// ft_putnbr_fd(stack->head_a->prev->prev->prev->number, 2);
		push_swap_push(stack->head_a, temp);
	}
	if (vars != NULL)
		push_swap_add_step(9, "rra\n", vars);
	return ;
}

void	push_swap_rrb(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_b) > 1)
	{
		temp = push_swap_pop(stack->head_b->prev->prev);
		push_swap_push(stack->head_b, temp);
	}
	if (vars != NULL)
		push_swap_add_step(10, "rrb\n", vars);
	return ;
}

void	push_swap_rrr(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_a) > 1)
	{
		temp = push_swap_pop(stack->head_a->prev->prev);
		push_swap_push(stack->head_a, temp);
	}
	if (push_swap_count_stack(stack->head_b) > 1)
	{
		temp = push_swap_pop(stack->head_b->prev->prev);
		push_swap_push(stack->head_b, temp);
	}
	if (vars != NULL)
		push_swap_add_step(11, "rrr\n", vars);
	return ;
}
