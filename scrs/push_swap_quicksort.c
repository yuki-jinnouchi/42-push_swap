/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 18:59:46 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_push_half(t_vars *vars);
void	push_swap_back_half(t_vars *vars);
void	push_swap_small_sort_pa(t_vars *vars);
void	push_swap_small_sort_ra(t_vars *vars);
void	push_swap_quicksort(t_vars *vars);

void	push_swap_push_half(t_vars *vars)
{
	t_stack		*temp;
	int			size;
	int			count;

	vars->avg = (vars->min + vars->max) / 2;
	size = vars->max - vars->min + 1;
	count = 0;
	while (count++ < size)
	{
		if (vars->head_a->next->order <= vars->avg)
			push_swap_pb(vars->pair, vars);
		else
			push_swap_ra(vars->pair, vars);
	}
	if (vars->min != 1)
	{
		size = vars-> max - vars->avg;
		count = 0;
		while (count++ < size)
			push_swap_rra(vars->pair, vars);
	}
	vars->dir = 0;
}

void	push_swap_back_half(t_vars *vars)
{
	int			count;

	vars->max = vars->avg;
	push_swap_push_pivot(vars);
	vars->avg = (vars->min + vars->max) / 2;
	count = 0;
	while (count < vars->max - vars->min + 1)
	{
		if (vars->head_b->next->order > vars->avg)
			push_swap_pa(vars->pair, vars);
		else
			push_swap_rb(vars->pair, vars);
		count++;
	}
	vars->dir = 0;
}

void	push_swap_small_sort_pa(t_vars *vars)
{
	int	size;

	vars->max = vars->avg;
	vars->avg = (vars->min + vars->max) / 2;
	size = push_swap_count_stack(vars->head_b);
	if (size > 1)
	{
		if (vars->head_b->next->order > vars->head_b->next->next->order)
			push_swap_sb(vars->pair, vars);
		push_swap_pa(vars->pair, vars);
		push_swap_ra(vars->pair, vars);
	}
	vars->min = vars->head_b->next->order + 1;
	push_swap_pa(vars->pair, vars);
	push_swap_ra(vars->pair, vars);
	vars->max = push_swap_pop_pivot(vars);
	vars->dir = 1;
	return ;
}

void	push_swap_small_sort_ra(t_vars *vars)
{
	int	size;

	size = vars->max - vars->min + 1;
	if (size > 1)
	{
		if (vars->head_a->next->order > vars->head_a->next->next->order)
			push_swap_sa(vars->pair, vars);
		push_swap_ra(vars->pair, vars);
	}
	vars->min = vars->head_a->next->order + 1;
	push_swap_ra(vars->pair, vars);
	vars->dir = 1;
	return ;
}

void	push_swap_quicksort(t_vars *vars)
{
	t_stack	*temp;

	push_swap_add_step(0, "st", vars);
	while (push_swap_is_pair_completed(vars->pair) == FALSE)
	{
		if (push_swap_count_stack(vars->head_b) == 0)
		{
			if (vars->dir == 0)
				push_swap_push_pivot(vars);
			if (vars->dir == 1)
				vars->max = push_swap_pop_pivot(vars);
			push_swap_push_half(vars);
		}
		else if (push_swap_count_stack(vars->head_b) < 3)
		{
			push_swap_small_sort_pa(vars);
			if (vars->max - vars->min < 3)
				push_swap_small_sort_ra(vars);
		}
		else
			push_swap_back_half(vars);
	}
}
