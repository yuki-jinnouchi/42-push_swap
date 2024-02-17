/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 19:05:16 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_exec(t_vars *vars);
int		main(int argc, char **argv);

void	push_swap_exec(t_vars *vars)
{
	int		flag;
	t_step	*temp_step;

	push_swap_quicksort(vars);
	flag = SUCCESS;
	while (flag == SUCCESS)
		flag = push_swap_step_optimize_2step(vars->head_step);
	temp_step = vars->head_step;
	while (temp_step->next != vars->head_step)
	{
		flag = SUCCESS;
		flag = push_swap_bfs(temp_step, vars);
		temp_step = temp_step->next;
	}
	while (flag == SUCCESS)
		flag = push_swap_step_optimize_2step(vars->head_step);
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
	push_swap_stack_init(argc, argv, vars);
	push_swap_vars_init(vars);
	if (argc == 2)
		push_swap_free_temp_args(vars);
	vars->arg_size = push_swap_count_stack(vars->head_a);
	if (push_swap_add_index(vars->head_a) == FAILURE)
		push_swap_error("index error", vars);
	push_swap_exec(vars);
	push_swap_free_vars(vars);
	return (SUCCESS);
}
