/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_dfs_move.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 19:08:43 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_avoid_error_move(int command, t_pair *pair);
void	push_swap_move_next_command(t_queue *queue, int depth_basis);
int		push_swap_move_init(t_queue *queue);
int		push_swap_move_up(t_queue *queue);
int		push_swap_move_queue(t_queue *queue, int limit_depth);

int	push_swap_avoid_error_move(int command, t_pair *pair)
{
	int	count_a;
	int	count_b;

	count_a = push_swap_count_stack(pair->head_a);
	count_b = push_swap_count_stack(pair->head_b);
	if (command == 1 && count_b == 0)
		command = 2;
	if (command == 2 && count_a == 0)
		command = 3;
	if (command == 3 && count_a == 0)
		command = 4;
	if (command == 4 && count_b == 0)
		command = 5;
	if (command == 5 && (count_a == 0 || count_b == 0))
		command = 6;
	while (((command == 6 || command == 9) && count_a < 2) || \
		((command == 7 || command == 10) && count_b < 2) || \
		((command == 8 || command == 11) && (count_a < 2 || count_b < 2)))
		command++;
	if (command > 11)
		command = 12;
	return (command);
}

void	push_swap_move_next_command(t_queue *queue, int depth_basis)
{
	int	depth;
	int	past_command;
	int	next_command;

	depth = queue->depth;
	past_command = queue->commands[queue->depth - 1];
	next_command = push_swap_avoid_error_move(past_command + 1, queue->pair);
	push_swap_move_pair(queue->pair, past_command, 1);
	if (next_command < 12)
	{
		push_swap_move_pair(queue->pair, next_command, 0);
		queue->commands[queue->depth - 1] = next_command;
	}
	else
	{
		queue->depth --;
		queue->commands[queue->depth - 1] = 0;
		queue->depth_basis++;
	}
	return ;
}

int	push_swap_move_init(t_queue *queue)
{
	int	new_depth;
	int	new_command;

	new_depth = queue->depth + 1;
	new_command = push_swap_avoid_error_move(1, queue->pair);
	queue->commands[new_depth - 1] = new_command;
	push_swap_move_pair(queue->pair, new_command, 0);
	queue->depth = new_depth;
	return (SUCCESS);
}

int	push_swap_move_up(t_queue *queue)
{
	int	past_command;
	int	next_command;

	past_command = queue->commands[queue->depth - 1];
	while (queue->depth > 0 && \
		push_swap_avoid_error_move(past_command + 1, queue->pair) > 11)
	{
		queue->commands[queue->depth - 1] = 0;
		push_swap_move_pair(queue->pair, past_command, 1);
		queue->depth--;
		if (queue->depth > 0)
			past_command = queue->commands[queue->depth - 1];
	}
	return (past_command);
}

void	push_swap_move_down(t_queue *queue)
{
	int	next_command;

	while (queue->depth < queue->depth_basis)
	{
		next_command = push_swap_avoid_error_move(1, queue->pair);
		queue->depth ++;
		queue->commands[queue->depth - 1] = next_command;
		push_swap_move_pair(queue->pair, next_command, 0);
	}
}

int	push_swap_move_queue(t_queue *queue, int limit_depth)
{
	int	past_command;
	int	next_command;

	if (queue->depth > limit_depth)
		return (FAILURE);
	if (queue->depth == 0 && queue->commands[0] == 0)
		return (push_swap_move_init(queue));
	push_swap_move_up(queue);
	if (queue->depth != 0)
	{
		past_command = queue->commands[queue->depth - 1];
		next_command = push_swap_avoid_error_move(\
			past_command + 1, queue->pair);
		if (next_command < 12)
			push_swap_move_next_command(queue, queue->depth_basis);
	}
	else
		queue->depth_basis ++;
	push_swap_move_down(queue);
	return (SUCCESS);
}
