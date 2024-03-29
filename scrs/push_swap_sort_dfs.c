/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_dfs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 19:10:56 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /*
// typedef struct s_step
// {
// 	char			*name;
// 	int				*int_name;
// 	struct s_stack	*copt_head_a;
// 	struct s_step	*next;
// }	t_step;
// */

t_queue	*push_swap_queue_init(t_step *head);
void	push_swap_move_pair(t_pair *pair, int command, int direction);
int		push_swap_count_step(t_step *head, t_vars *vars);
int		push_swap_valid_queue(t_queue *queue, int step_ahead, t_vars *vars);
int		push_swap_bfs(t_step *head, t_vars *vars);

t_queue	*push_swap_queue_init(t_step *head)
{
	t_queue	*queue;
	int		i;

	queue = (t_queue *) malloc(sizeof(t_queue));
	queue->commands = (int *) malloc(sizeof(int) * (DEPTH_MAX + 1));
	i = 0;
	while (i <= DEPTH_MAX)
		queue->commands[i++] = 0;
	queue->depth = 0;
	queue->depth_basis = 1;
	queue->pair = push_swap_copy_pair(head->pair);
	queue->root_head_a = head;
	return (queue);
}

void	push_swap_move_pair(t_pair *pair, int command, int direction)
{
	if ((command == 1 && direction == 0) || (command == 2 && direction == 1))
		push_swap_pa(pair, NULL);
	if ((command == 2 && direction == 0) || (command == 1 && direction == 1))
		push_swap_pb(pair, NULL);
	if ((command == 3 && direction == 0) || (command == 3 && direction == 1))
		push_swap_sa(pair, NULL);
	if ((command == 4 && direction == 0) || (command == 4 && direction == 1))
		push_swap_sb(pair, NULL);
	if ((command == 5 && direction == 0) || (command == 5 && direction == 1))
		push_swap_ss(pair, NULL);
	if ((command == 6 && direction == 0) || (command == 9 && direction == 1))
		push_swap_ra(pair, NULL);
	if ((command == 7 && direction == 0) || (command == 10 && direction == 1))
		push_swap_rb(pair, NULL);
	if ((command == 8 && direction == 0) || (command == 11 && direction == 1))
		push_swap_rr(pair, NULL);
	if ((command == 9 && direction == 0) || (command == 6 && direction == 1))
		push_swap_rra(pair, NULL);
	if ((command == 10 && direction == 0) || (command == 7 && direction == 1))
		push_swap_rrb(pair, NULL);
	if ((command == 11 && direction == 0) || (command == 8 && direction == 1))
		push_swap_rrr(pair, NULL);
	return ;
}

int	push_swap_count_step(t_step *head, t_vars *vars)
{
	t_step	*temp;
	int		count;

	temp = head;
	count = 0;
	while (temp->next != vars->head_step)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	push_swap_valid_queue(t_queue *queue, int step_ahead, t_vars *vars)
{
	t_step	*temp;
	t_pair	*temp_pair;
	int		count;
	int		flag;

	flag = FAILURE;
	temp = queue->root_head_a;
	count = 0;
	while (count < step_ahead && count < 10)
	{
		temp = temp->next;
		count ++;
	}
	while (count > 0 && flag == FAILURE)
	{
		if (count > queue->depth && \
			push_swap_pairs_compare_order(temp->pair, queue->pair) == TRUE)
		{
			flag = SUCCESS;
			queue->find_length = count;
		}
		temp = temp->prev;
		count--;
	}
	return (flag);
}

int	push_swap_renew_step(t_queue *queue, t_step *head, \
	int find_length, t_vars *vars)
{
	t_step	*temp_step;
	t_pair	*temp_pair;
	t_step	*tail;
	t_step	*next;
	int		count;

	temp_step = head->next;
	count = 0;
	while (count < queue->depth)
	{
		temp_step->int_command = queue->commands[count];
		free(temp_step->command);
		temp_step->command = NULL;
		temp_pair = push_swap_copy_pair(temp_step->prev->pair);
		push_swap_free_pair(temp_step->pair);
		push_swap_move_pair(temp_pair, temp_step->int_command, 0);
		temp_step->pair = temp_pair;
		temp_step = temp_step->next;
		count++;
	}
	tail = temp_step->prev;
	while (count < find_length)
	{
		next = temp_step->next;
		push_swap_free_one_step(temp_step);
		temp_step = next;
		count++;
	}
	tail->next = temp_step;
	temp_step->prev = tail;
	return (count);
}

int	push_swap_bfs(t_step *head, t_vars *vars)
{
	t_queue	*queue;
	int		command;
	int		flag;
	int		flag2;
	int		step_ahead;

	flag = FAILURE;
	flag2 = SUCCESS;
	step_ahead = push_swap_count_step(head, vars);
	if (step_ahead < 2)
		return (FAILURE);
	queue = push_swap_queue_init(head);
	while (queue->depth < DEPTH_MAX && flag == FAILURE && flag2 == SUCCESS)
	{
		flag2 = push_swap_move_queue(queue, step_ahead);
		if (push_swap_valid_queue(queue, step_ahead, vars) == SUCCESS)
			flag = SUCCESS;
	}
	if (flag == SUCCESS)
		push_swap_renew_step(queue, queue->root_head_a, \
			queue->find_length, vars);
	push_swap_free_queue(queue);
	return (flag);
}
