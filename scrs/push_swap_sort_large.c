/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_large.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 11:07:29 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_location	*ptr)
{
	t_location *temp;

	temp = ptr;
	while(temp != NULL)
	{
		printf("++ stack: min: %i, max: %i, med: %i\n", temp->min, temp->max, temp->median);
		temp = temp->next;
	}
	printf("++ stack: NULL\n");
}

void print_status(t_vars *vars)
{
	// sleep(1);
	ft_printf("min: %i, max: %i, median:%i, piv:%p\n", vars->min, vars->max, vars->median, vars->pivot);
	print_stack(vars->pivot);
}


void	push_swap_push_half(t_vars *vars)
{
	t_stack		*temp;
	int 		size;
	int			count;

	ft_putstr_fd("push_swap_push_half\n", 1);
	print_status(vars);

	push_swap_set_pivot(vars);
	temp = vars->head_a->prev;
	size = vars->max - vars->min + 1;

	print_status(vars);

	count = 0;
	while(count < size)
	{
		if (vars->head_a->next->order <= vars->median)
			push_swap_pushes(vars->head_b);
		else
			push_swap_rotates(vars->head_a, 0);
		count ++;
	}
	if (vars->min != 1)
	{
		size = vars-> max - vars->median;
		count = 0;
		while(count++ < size)
			push_swap_reverse_rotates(vars->head_a, 0);
	}
	push_swap_push_loc(vars->median, vars);
}

void	push_swap_small_sort_push_a(t_vars *vars)
{
	ft_putstr_fd("push_swap_small_sort_push_a\n", 1);
	print_status(vars);

	// vars->max = vars->median;
	vars->max = push_swap_pop_loc(vars);

	print_status(vars);


	if (push_swap_count_stack(vars->head_b) == 1)
	{
		// vars->fixed = vars->head_b->next;
		vars->min = vars->head_b->next->order + 1;
		push_swap_pushes(vars->head_a);
		push_swap_rotates(vars->head_a, 0);
		ft_putstr_fd("ue?", 1);
		return ;
	}
	if (vars->head_b->next->order < vars->head_b->next->next->order)
		push_swap_swaps(vars->head_b, 0);
	vars->min = vars->head_b->next->order + 1;
	// vars->max = push_swap_pop_loc(vars);
	push_swap_pushes(vars->head_a);
	push_swap_pushes(vars->head_a);
	push_swap_rotates(vars->head_a, 0);
	push_swap_rotates(vars->head_a, 0);
	ft_putstr_fd("sita?", 1);
	return ;
}

void	push_swap_small_sort_rotate_a(t_vars *vars)
{
	ft_putstr_fd("push_swap_small_sort_rotate_a\n", 1);

	print_status(vars);

	// push_swap_pop_loc(vars);
 

	print_status(vars);

	printf("++ stack: min: %i, max: %i, med: %i\n", vars->min, vars->max, vars->median);
	ft_putnbr_fd(vars->max - vars->min, 1);
	if (vars->max - vars->min == 0)
	{
		// vars->fixed = vars->head_a->next;
		vars->min = vars->head_a->next->order + 1;
		push_swap_rotates(vars->head_a, 0);
		ft_putstr_fd("ue?", 1);
		return ;
		
	}
	else if (vars->head_a->next->order > vars->head_a->next->next->order)
		push_swap_swaps(vars->head_a, 0);
	// vars->fixed = vars->head_a->next;
		ft_putstr_fd("sita?", 1);
	vars->min = vars->head_a->next->next->order + 1;
	// vars->max = push_swap_pop_loc(vars);
	push_swap_rotates(vars->head_a, 0);
	push_swap_rotates(vars->head_a, 0);
	return ;
}

void	push_swap_push_back_half(t_vars *vars)
{
	t_stack		*temp;
	int			count;

	ft_putstr_fd("push_swap_push_back_half\n", 1);

	print_status(vars);

	vars->max = vars->median;
	vars->median = (vars->max + vars->min) / 2;
	temp = vars->head_b->next;

	print_status(vars);

	count = 0;
	while(count < vars->max - vars->min + 1)
	{
		if (vars->head_b->next->order > vars->median)
			push_swap_pushes(vars->head_a);
		else
			push_swap_rotates(vars->head_b, 0);
		count++;
	}
	push_swap_push_loc(vars->median, vars);
}

void	push_swap_set_pivot(t_vars *vars)
{
	int median;

	ft_putstr_fd("push_swap_set_pivot\n", 1);

	// print_status(vars);

	// if (vars->pivot == NULL)
	// 	vars->min = 1;
	// else
	// 	vars->min = vars->fixed->order + 1;

	if (vars->pivot == NULL)
		vars->max = vars->arg_size;
	else
		vars->max = push_swap_pop_loc(vars);
	median = (vars->min + vars->max - 1) / 2;
	vars->median = median;

	// print_status(vars);

	// push_swap_push_loc(median, vars);
}

void	push_swap_quicksort(t_vars *vars)
{
	t_stack	*temp;

	// vars->min = 1;
	// vars->max = vars->arg_size;
	while (push_swap_is_sorted(vars->head_a) == FALSE || \
		push_swap_count_stack(vars->head_b) != 0)
	{
		// printf("size a: %i  ", push_swap_count_stack(vars->head_a));
		// printf("size b: %i\n", push_swap_count_stack(vars->head_b));
		if (push_swap_count_stack(vars->head_b) == 0)
			push_swap_push_half(vars);
			//get helf till a's pivot or fixed
		else if (push_swap_count_stack(vars->head_b) < 3)
		{
			push_swap_small_sort_push_a(vars);
			// push_swap_print_stack(vars->head_a);
			// push_swap_print_stack(vars->head_b);
			//sort & back
					ft_putstr_fd("numbers:\n", 1);
		ft_putstr_fd("stack a: ", 1); push_swap_print_stack(vars->head_a);
		ft_putstr_fd("stack b: ", 1); push_swap_print_stack(vars->head_b);
		ft_putstr_fd("orders:\n", 1);
		ft_putstr_fd("stack a: ", 1); push_swap_print_stack_order(vars->head_a);
		ft_putstr_fd("stack b: ", 1); push_swap_print_stack_order(vars->head_b);
		ft_putchar_fd('\n', 1);
			if (vars->max - vars->min < 3)
				push_swap_small_sort_rotate_a(vars);
		}
		else
			push_swap_push_back_half(vars);
			// def pivot & give half till median
		ft_putstr_fd("numbers:\n", 1);
		ft_putstr_fd("stack a: ", 1); push_swap_print_stack(vars->head_a);
		ft_putstr_fd("stack b: ", 1); push_swap_print_stack(vars->head_b);
		ft_putstr_fd("orders:\n", 1);
		ft_putstr_fd("stack a: ", 1); push_swap_print_stack_order(vars->head_a);
		ft_putstr_fd("stack b: ", 1); push_swap_print_stack_order(vars->head_b);
		ft_putchar_fd('\n', 1);
		sleep(1);
	}
}
