/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_log_steps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 20:38:56 by yjinnouc         ###   ########.fr       */
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

int	push_swap_2stack_compare_wrap(t_stack head_i, t_stack head_j)
{
	if (push_swap_stack_compare(head_i, head_j) == FALSE)
		return (FALSE);
	if (push_swap_stack_compare(head_i->opposite, head_j->opposite) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	push_swap_stack_compare(t_stack head_i, t_stack head_j)
{
	t_stack	temp_i;
	t_stack	temp_j;

	temp_i = head_i;
	temp_j = head_j;
	while (temp_i != head_i)
	{
		if (temp_i->number != temp_j->number)
			return (FALSE);
		temp_i = temp_i->next;
		temp_j = temp_j->next;
	}
	if (temp_j != head_j)
		return (FALSE);
	return (SUCCESS);
}

void	push_swap_add_step(t_step *add, t_vars vars)
{
	t_step	*last;

	last = vars->head_step->prev;
	vars->head_step->prev = add;
	last->next = add;
	add->prev = last;
	add->next = vars->head_step;
}

void	push_swap_log_steps(t_vars *vars, char *command, int int_command)
{
	t_step	*temp;

	temp = malloc(sizeof(steps));
	if (temp == NULL)
		return ;
	temp->command = command;
	temp->int_command = int_command;
	temp->copy_head_a = push_swap_copy_stack(vars->head_a);
	temp->copy_head_a->opposite = push_swap_copy_stack(vars->head_b);
	push_swap_add_step(temp, vars);
}
