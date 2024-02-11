/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:03:01 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/11 02:19:17 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*pa (push a): Take the first element at the top of b
and put it at the top of a. Do nothing if b is empty.*/
/*pb (push b): Take the first element at the top of a
and put it at the top of b. Do nothing if a is empty.*/

void	push_swap_pushes(t_stack *head_a, t_stack *head_b, int i)
{
	t_stack	*temp;

	if (i == 0)
	{
		temp = push_swap_pop(head_b);
		push_swap_push(head_a, temp);
		ft_putstr_fd("pa\n", 1);
	}
	if (i == 1)
	{
		temp = push_swap_pop(head_a);
		push_swap_push(head_b, temp);
		ft_putstr_fd("pb\n", 1);
	}
}

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
/*sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
/*ss : sa and sb at the same time.*/

void	push_swap_swaps(t_stack *head_a, t_stack *head_b, int i)
{
	t_stack	*temp;

	if (i == 0 || i == 2)
	{
		temp = push_swap_pop(head_a);
		push_swap_push(head_a->prev, temp);
	}
	if (i == 1 || i == 2)
	{
		temp = push_swap_pop(head_b);
		push_swap_push(head_b->prev, temp);
	}
	if (i == 0)
		ft_putstr_fd("sa\n", 1);
	if (i == 1)
		ft_putstr_fd("sb\n", 1);
	if (i == 2)
		ft_putstr_fd("ss\n", 1);
}

/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
/*rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
/*rr : ra and rb at the same time*/

void	push_swap_rotates(t_stack *head_a, t_stack *head_b, int i)
{
	t_stack	*temp;

	if (i == 0 || i == 2)
	{
		temp = push_swap_pop(head_a);
		push_swap_push(head_a->next, temp);
	}
	if (i == 1 || i == 2)
	{
		temp = push_swap_pop(head_b);
		push_swap_push(head_b->next, temp);
	}
	if (i == 0)
		ft_putstr_fd("ra\n", 1);
	if (i == 1)
		ft_putstr_fd("rb\n", 1);
	if (i == 2)
		ft_putstr_fd("rr\n", 1);
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
/*rrr : rra and rrb at the same time.*/

void	push_swap_reverse_rotates(t_stack *head_a, t_stack *head_b, int i)
{
	t_stack	*temp;

	if (i == 0 || i == 2)
	{
		temp = push_swap_pop(head_a->next);
		push_swap_push(head_a, temp);
	}
	if (i == 0 || i == 2)
	{
		temp = push_swap_pop(head_b->next);
		push_swap_push(head_b, temp);
	}
	if (i == 0)
		ft_putstr_fd("rra\n", 1);
	if (i == 1)
		ft_putstr_fd("rrb\n", 1);
	if (i == 2)
		ft_putstr_fd("rrr\n", 1);
}
