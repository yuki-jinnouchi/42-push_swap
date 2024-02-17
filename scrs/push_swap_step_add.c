/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_step_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 18:41:06 by yjinnouc         ###   ########.fr       */
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

void	push_swap_add_step(int int_command, char *command, t_vars *vars);

void	push_swap_add_step(int int_command, char *command, t_vars *vars)
{
	t_step	*temp;
	t_step	*last;

	temp = malloc(sizeof(t_step));
	if (temp == NULL)
		push_swap_error("step malloc error", vars);
	temp->command = ft_strdup(command);
	temp->int_command = int_command;
	temp->pair = push_swap_copy_pair(vars->pair);
	// temp->copy_head_a = push_swap_copy_stack(vars->head_a);
	// temp->copy_head_a->opposite = push_swap_copy_stack(vars->head_b);
	// temp->copy_head_a->opposite->opposite = temp->copy_head_a;
	// push_swap_push_step(temp, vars);
	if (vars->head_step == NULL)
	{
		vars->head_step = temp;
		vars->head_step->next = temp;
		vars->head_step->prev = temp;
		return ;
	}
	last = vars->head_step->prev;
	vars->head_step->prev = temp;
	last->next = temp;
	temp->prev = last;
	temp->next = vars->head_step;
	return ;
}
