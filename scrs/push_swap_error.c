/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/14 09:10:14 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_free_stack(t_stack *head);
void	push_swap_free_pivot(t_pivot *head);
void	push_swap_error(char *message, t_vars *vars);

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

void	push_swap_error(char *message, t_vars *vars)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (vars->head_a)
		push_swap_free_stack(vars->head_a);
	if (vars->head_b)
		push_swap_free_stack(vars->head_b);
	if (vars->pivot != NULL)
		push_swap_free_pivot(vars->pivot);
	if (vars)
		free(vars);
	// if (ptr)
	// 	free(ptr);
	if (errno)
		exit (errno);
	exit (EXIT_FAILURE);
}
