/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/14 07:41:49 by yjinnouc         ###   ########.fr       */
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
		push_swap_push_pivot(vars);
	if (vars->dir == 1)
		vars->max = push_swap_pop_pivot(vars);
	vars->avg = (vars->min + vars->max) / 2;
	size = vars->max - vars->min + 1;
	count = 0;
	while (count < size)
	{
		if (vars->head_a->next->order <= vars->avg)
			push_swap_pushes(vars->head_b, vars);
		else
			push_swap_rotates(vars->head_a, 0, vars);
		count ++;
	}
	if (vars->min != 1)
	{
		size = vars-> max - vars->avg;
		count = 0;
		while (count++ < size)
			push_swap_reverse_rotates(vars->head_a, 0, vars);
	}
	vars->dir = 0;
}

void	push_swap_back_half(t_vars *vars)
{
	int			count;

	// ft_putstr_fd(" --- push_swap_back_half --- \n", 1);
	vars->max = vars->avg;
	push_swap_push_pivot(vars);
	vars->avg = (vars->min + vars->max) / 2;
	count = 0;
	while (count < vars->max - vars->min + 1)
	{
		if (vars->head_b->next->order > vars->avg)
			push_swap_pushes(vars->head_a, vars);
		else
			push_swap_rotates(vars->head_b, 0, vars);
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
			push_swap_swaps(vars->head_b, 0, vars);
		push_swap_pushes(vars->head_a, vars);
		push_swap_rotates(vars->head_a, 0, vars);
	}
	vars->min = vars->head_b->next->order + 1;
	push_swap_pushes(vars->head_a, vars);
	push_swap_rotates(vars->head_a, 0, vars);
	vars->max = push_swap_pop_pivot(vars);
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
			push_swap_swaps(vars->head_a, 0, vars);
		push_swap_rotates(vars->head_a, 0, vars);
	}
	vars->min = vars->head_a->next->order + 1;
	push_swap_rotates(vars->head_a, 0, vars);
	vars->dir = 1;
	return ;
}

void	push_swap_quicksort(t_vars *vars)
{
	t_stack	*temp;

	push_swap_log_steps(0, "st", vars);
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
