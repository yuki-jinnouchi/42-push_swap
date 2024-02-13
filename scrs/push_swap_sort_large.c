/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_large.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 20:43:55 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_push_half(t_vars *vars);
void	push_swap_back_half(t_vars *vars);
void	push_swap_small_sort_push_a(t_vars *vars);
void	push_swap_small_sort_rotate_a(t_vars *vars);
void	push_swap_quicksort(t_vars *vars);

void	push_swap_push_half(t_vars *vars)
{
	t_stack		*temp;
	int			size;
	int			count;

	// ft_putstr_fd(" --- push_swap_push_half --- \n", 1);
	if (vars->dir == 0)
		push_swap_push_loc(vars);
	if (vars->dir == 1)
		vars->max = push_swap_pop_loc(vars);
	vars->avg = (vars->min + vars->max) / 2;
	size = vars->max - vars->min + 1;
	count = 0;
	while (count < size)
	{
		if (vars->head_a->next->order <= vars->avg)
			push_swap_pushes(vars->head_b);
		else
			push_swap_rotates(vars->head_a, 0);
		count ++;
	}
	if (vars->min != 1)
	{
		size = vars-> max - vars->avg;
		count = 0;
		while (count++ < size)
			push_swap_reverse_rotates(vars->head_a, 0);
	}
	vars->dir = 0;
}

void	push_swap_back_half(t_vars *vars)
{
	int			count;

	// ft_putstr_fd(" --- push_swap_back_half --- \n", 1);
	vars->max = vars->avg;
	push_swap_push_loc(vars);
	vars->avg = (vars->min + vars->max) / 2;
	count = 0;
	while (count < vars->max - vars->min + 1)
	{
		if (vars->head_b->next->order > vars->avg)
			push_swap_pushes(vars->head_a);
		else
			push_swap_rotates(vars->head_b, 0);
		count++;
	}
	vars->dir = 0;
}

void	push_swap_small_sort_push_a(t_vars *vars)
{
	int	size;

	// ft_putstr_fd(" --- push_swap_small_sort_push_a --- \n", 1);
	vars->max = vars->avg;
	vars->avg = (vars->min + vars->max) / 2;
	size = push_swap_count_stack(vars->head_b);
	if (size > 1)
	{
		if (vars->head_b->next->order > vars->head_b->next->next->order)
			push_swap_swaps(vars->head_b, 0);
		push_swap_pushes(vars->head_a);
		push_swap_rotates(vars->head_a, 0);
	}
	vars->min = vars->head_b->next->order + 1;
	push_swap_pushes(vars->head_a);
	push_swap_rotates(vars->head_a, 0);
	vars->max = push_swap_pop_loc(vars);
	vars->dir = 1;
	return ;
}

void	push_swap_small_sort_rotate_a(t_vars *vars)
{
	int	size;

	// ft_putstr_fd(" --- push_swap_small_sort_rotate_a --- \n", 1);
	size = vars->max - vars->min + 1;
	if (size > 1)
	{
		if (vars->head_a->next->order > vars->head_a->next->next->order)
			push_swap_swaps(vars->head_a, 0);
		push_swap_rotates(vars->head_a, 0);
	}
	vars->min = vars->head_a->next->order + 1;
	push_swap_rotates(vars->head_a, 0);
	vars->dir = 1;
	return ;
}

void	push_swap_quicksort(t_vars *vars)
{
	t_stack	*temp;

	while (push_swap_is_sorted(vars->head_a) == FALSE || \
		push_swap_count_stack(vars->head_b) != 0)
	{
		if (push_swap_count_stack(vars->head_b) == 0)
			push_swap_push_half(vars);
		else if (push_swap_count_stack(vars->head_b) < 3)
		{
			push_swap_small_sort_push_a(vars);
			if (vars->max - vars->min < 3)
				push_swap_small_sort_rotate_a(vars);
		}
		else
			push_swap_back_half(vars);
		// print_status(vars);
	}
}
