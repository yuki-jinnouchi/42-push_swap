/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/15 16:09:19 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_exec(t_vars *vars);

void	push_swap_exec(t_vars *vars)
{
	vars->arg_size = push_swap_count_stack(vars->head_a);
	if (push_swap_add_index(vars->head_a) == FAILURE)
		push_swap_error("index error", vars);
	push_swap_quicksort(vars);
	push_swap_print_step(vars->head_step, vars);
}
