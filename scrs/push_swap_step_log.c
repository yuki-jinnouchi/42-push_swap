/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_step_log.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/15 16:00:09 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
typedef struct s_step
{
	char			*command;
	int				*int_command;
	struct s_stack	*copy_head_a;
	struct s_step	*next;
	struct s_step	*prev;
}	t_step;
*/

// void	push_swap_add_step(t_step *new_step, t_vars *vars);
// void	push_swap_log_steps(int int_command, char *command, t_vars *vars);

void	push_swap_add_step(t_step *new_step, t_vars *vars)
{
	t_step	*last;

	if (vars->head_step == NULL)
	{
		vars->head_step = new_step;
		vars->head_step->next = new_step;
		vars->head_step->prev = new_step;
		return ;
	}
	last = vars->head_step->prev;
	vars->head_step->prev = new_step;
	last->next = new_step;
	new_step->prev = last;
	new_step->next = vars->head_step;
	return ;
}

void	push_swap_log_steps(int int_command, char *command, t_vars *vars)
{
	t_step	*temp;

	temp = malloc(sizeof(t_step));
	if (temp == NULL)
		return ;
	temp->command = ft_strdup(command);
	temp->int_command = int_command;
	// temp->depth = 0;
	// temp->max_command = 0;
	temp->copy_head_a = push_swap_copy_stack(vars->head_a);
	temp->copy_head_a->opposite = push_swap_copy_stack(vars->head_b);
	temp->copy_head_a->opposite->opposite = temp->copy_head_a;
	push_swap_add_step(temp, vars);
	return ;
}
