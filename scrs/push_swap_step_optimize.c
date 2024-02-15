/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_step_optimize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/14 10:17:41 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    push_swap_skip_2step(t_step *step)
{
	step->next->next->prev = step->prev;
	step->prev->next = step->next->next;
	push_swap_free_stack(step->next->copy_head_a->opposite);
	push_swap_free_stack(step->next->copy_head_a);
	free(step->next->command);
	free(step->next);
	push_swap_free_stack(step->copy_head_a->opposite);
	push_swap_free_stack(step->copy_head_a);
	free(step->command);
	free(step);
	return (SUCCESS);
}

int push_swap_step_optimize_2step(t_step *head)
{
	t_step  *temp;
	t_step	*next;
	int		flag;

	flag = FAILURE;
	temp = head->next;
	while (temp->next->next != head)
	{
		if ((temp->int_command == 1 && temp->next->int_command == 2) || \
			(temp->int_command == 2 && temp->next->int_command == 1) || \
			(temp->int_command == 6 && temp->next->int_command == 9) || \
			(temp->int_command == 7 && temp->next->int_command == 10) || \
			(temp->int_command == 8 && temp->next->int_command == 11) || \
			(temp->int_command == 9 && temp->next->int_command == 6) || \
			(temp->int_command == 10 && temp->next->int_command == 7) || \
			(temp->int_command == 11 && temp->next->int_command == 8) || \
			(temp->int_command == 3 && temp->next->int_command == 3) || \
			(temp->int_command == 4 && temp->next->int_command == 4) || \
			(temp->int_command == 5 && temp->next->int_command == 5))
		{
			next = temp->next->next;
			flag = push_swap_skip_2step(temp);
			temp = next;
		}
		else
			temp = temp->next;
	}
	return (flag);
}
