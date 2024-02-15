/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/15 17:06:24 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_exec(t_vars *vars);
int		main(int argc, char **argv);

void	push_swap_exec(t_vars *vars)
{
	vars->arg_size = push_swap_count_stack(vars->head_a);
	if (push_swap_add_index(vars->head_a) == FAILURE)
		push_swap_error("index error", vars);
	push_swap_quicksort(vars);
	push_swap_print_step(vars->head_step, vars);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc < 2)
		push_swap_error("argument must be more than 1", NULL);
	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		push_swap_error("vars malloc error", vars);
	push_swap_init(argc, argv, vars);
	push_swap_exec(vars);
	push_swap_free_vars(vars);
	return (SUCCESS);
}
