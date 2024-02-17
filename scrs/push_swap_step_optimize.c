/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_step_optimize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 19:09:36 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_step_optimize_2step(t_step *head);
int	push_swap_skip_2step(t_step *step);

int	push_swap_skip_2step(t_step *step)
{
	step->next->next->prev = step->prev;
	step->prev->next = step->next->next;
	push_swap_free_pair(step->next->pair);
	free(step->next->command);
	free(step->next);
	push_swap_free_pair(step->pair);
	free(step->command);
	free(step);
	return (SUCCESS);
}

int	push_swap_step_optimize_2step(t_step *head)
{
	t_step	*temp;
	t_step	*next;
	int		flag;

	flag = FAILURE;
	temp = head;
	while (temp->next->next != head)
	{
		next = temp->next;
		if ((next->int_command == 1 && next->next->int_command == 2) || \
			(next->int_command == 2 && next->next->int_command == 1) || \
			(next->int_command == 3 && next->next->int_command == 3) || \
			(next->int_command == 4 && next->next->int_command == 4) || \
			(next->int_command == 5 && next->next->int_command == 5) || \
			(next->int_command == 6 && next->next->int_command == 9) || \
			(next->int_command == 7 && next->next->int_command == 10) || \
			(next->int_command == 8 && next->next->int_command == 11) || \
			(next->int_command == 9 && next->next->int_command == 6) || \
			(next->int_command == 10 && next->next->int_command == 7) || \
			(next->int_command == 11 && next->next->int_command == 8))
			flag = push_swap_skip_2step(next);
		else
			temp = temp->next;
	}
	return (flag);
}
