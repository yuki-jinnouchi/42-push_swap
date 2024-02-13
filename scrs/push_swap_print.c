/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 21:03:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_pivot	*ptr);
void	print_status(t_vars *vars);

void	print_stack(t_pivot	*ptr)
{
	t_pivot	*temp;

	temp = ptr;
	while (temp != NULL)
	{
		printf("++ stack: max: %i\n", temp->max);
		temp = temp->next;
	}
	printf("++ stack: NULL\n\n");
}

void	print_status(t_vars *vars)
{
	printf("max: %i, piv:%p\n", vars->max, vars->pivot);
	print_stack(vars->pivot);
}
