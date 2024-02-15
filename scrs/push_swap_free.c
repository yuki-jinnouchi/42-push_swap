/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/15 17:11:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_free_vars(t_vars *vars);
void	push_swap_free_stack(t_stack *head);
void	push_swap_free_pivot(t_pivot *head);
void	push_swap_free_step(t_step *head);

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

void	push_swap_free_step(t_step *head)
{
	t_step	*temp;
	t_step	*prev;

	temp = head->next;
	while (temp!= head)
	{
		push_swap_free_stack(temp->copy_head_a->opposite);
		push_swap_free_stack(temp->copy_head_a);
		free(temp->command);
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	push_swap_free_stack(temp->copy_head_a->opposite);
	push_swap_free_stack(temp->copy_head_a);
	free(temp->command);
	free(temp);
	head = NULL;
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

