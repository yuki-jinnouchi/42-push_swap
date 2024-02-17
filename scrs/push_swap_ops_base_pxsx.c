/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_base_pxsx.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:03:01 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 05:53:40 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_pa(t_pair *stack, t_vars *vars);
void	push_swap_pb(t_pair *stack, t_vars *vars);
void	push_swap_sa(t_pair *stack, t_vars *vars);
void	push_swap_sb(t_pair *stack, t_vars *vars);
void	push_swap_ss(t_pair *stack, t_vars *vars);

/*pa (push a): Take the first element at the top of b
and put it at the top of a. Do nothing if b is empty.*/
/*pb (push b): Take the first element at the top of a
and put it at the top of b. Do nothing if a is empty.*/

void	push_swap_pa(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_b) > 0)
	{
		temp = push_swap_pop(stack->head_b);
		push_swap_push(stack->head_a, temp);
	}
	if (vars != NULL)
		push_swap_add_step(1, "pa\n", vars);
	return ;
}

void	push_swap_pb(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_a) > 0)
	{
		temp = push_swap_pop(stack->head_a);
		push_swap_push(stack->head_b, temp);
	}
	if (vars != NULL)
		push_swap_add_step(2, "pb\n", vars);
	return ;
}

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
/*sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
/*ss : sa and sb at the same time.*/

void	push_swap_sa(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_a) > 1)
	{
		temp = push_swap_pop(stack->head_a);
		push_swap_push(stack->head_a->next, temp);
	}
	if (vars != NULL)
		push_swap_add_step(3, "sa\n", vars);
	return ;
}

void	push_swap_sb(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_b) > 1)
	{
		temp = push_swap_pop(stack->head_b);
		push_swap_push(stack->head_b->next, temp);
	}
	if (vars != NULL)
		push_swap_add_step(4, "sb\n", vars);
	return ;
}

void	push_swap_ss(t_pair *stack, t_vars *vars)
{
	t_stack	*temp;

	if (push_swap_count_stack(stack->head_a) > 1)
	{
		temp = push_swap_pop(stack->head_a);
		push_swap_push(stack->head_a->next, temp);
	}
	if (push_swap_count_stack(stack->head_b) > 1)
	{
		temp = push_swap_pop(stack->head_b);
		push_swap_push(stack->head_b->next, temp);
	}
	if (vars != NULL)
		push_swap_add_step(5, "ss\n", vars);
	return ;
}
