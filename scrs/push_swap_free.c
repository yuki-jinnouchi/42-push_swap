/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 18:51:27 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_free_temp_args(t_vars *vars);
void	push_swap_free_pair(t_pair *pair);
void	push_swap_free_vars(t_vars *vars);
void	push_swap_free_stack(t_stack *head);
void	push_swap_free_pivot(t_pivot *head);

void	push_swap_free_temp_args(t_vars *vars)
{
	int	arg_count;

	if (vars->arg_temp)
	{
		arg_count = 0;
		while (vars->arg_temp[arg_count] != NULL)
		{
			free(vars->arg_temp[arg_count]++);
			arg_count++;
		}
		free(vars->arg_temp);
	}
	vars->arg_temp = NULL;
}

void	push_swap_free_pair(t_pair *pair)
{
	if (pair->head_a != NULL)
		push_swap_free_stack(pair->head_a);
	if (pair->head_b != NULL)
		push_swap_free_stack(pair->head_b);
	free(pair);
}

void	push_swap_free_vars(t_vars *vars)
{
	if (vars->head_a)
		push_swap_free_stack(vars->head_a);
	if (vars->head_b)
		push_swap_free_stack(vars->head_b);
	if (vars->head_pivot)
		push_swap_free_pivot(vars->head_pivot);
	if (vars->head_step)
		push_swap_free_step(vars->head_step);
	if (vars->pair)
		free(vars->pair);
	free(vars);
	return ;
}

void	push_swap_free_stack(t_stack *head)
{
	t_stack	*next;
	t_stack	*temp;

	if (head == NULL)
		return ;
	temp = head->next;
	while (temp != head)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	return ;
}

void	push_swap_free_pivot(t_pivot *head)
{
	t_pivot	*next;
	t_pivot	*temp;

	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		free(temp);
	}
	head = NULL;
	return ;
}
