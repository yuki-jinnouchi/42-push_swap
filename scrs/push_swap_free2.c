/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 18:40:10 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_free_step(t_step *head);
void	push_swap_free_one_step(t_step *step);
void	push_swap_free_queue(t_queue *queue);

void	push_swap_free_step(t_step *head)
{
	t_step	*temp;
	t_step	*prev;

	temp = head->next;
	while (temp!= head)
	{
		push_swap_free_pair(temp->pair);
		free(temp->command);
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	push_swap_free_pair(temp->pair);
	free(temp->command);
	free(temp);
	head = NULL;
	return ;
}

void	push_swap_free_one_step(t_step *step)
{
	push_swap_free_pair(step->pair);
	free(step->command);
	free(step);
	return ;
}

// void	push_swap_free_dummy_step(t_step *head) TODO: remove
// {
// 	t_step	*temp;
// 	t_step	*prev;

// 	temp = head->next;
// 	while (temp != head)
// 	{
// 		prev = temp;
// 		temp = temp->next;
// 		free(prev);
// 	}
// 	free(temp);
// 	return ;
// }

void	push_swap_free_queue(t_queue *queue)
{
	free(queue->commands);
	push_swap_free_pair(queue->pair);
	free(queue);
	return ;
}
