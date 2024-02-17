/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 09:32:51 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_print_stack(t_stack *head);
void	push_swap_print_stack_order(t_stack *head);
void	print_stack(t_pivot	*ptr);
void	print_status(t_vars *vars);
void	print_queue(t_queue *queue);

void	push_swap_print_stack(t_stack *head)
{
	t_stack	*temp;

	temp = head->next;
	while (temp != head)
	{
		ft_putnbr_fd(temp->order, 1);
		ft_putchar_fd(' ', 1);
		temp = temp->next;
	}
	ft_putchar_fd('\n', 1);
	return ;
}

void	push_swap_print_stack_order(t_stack *head)
{
	t_stack	*temp;

	fprintf(stderr, "pso:");
	temp = head->next;
	while (temp != head)
	{
		ft_putnbr_fd(temp->order, 2);
		ft_putchar_fd(' ', 2);
		temp = temp->next;
	}
	ft_putchar_fd('\n', 2);
	return ;
}

void	print_stack(t_pivot	*ptr)
{
	t_pivot	*temp;

	temp = ptr;
	while (temp != NULL)
	{
		printf("++ stack: max: %i\n", temp->max);
		temp = temp->next;
	}
	printf("++ stack: NULL\n\n");
	return ;
}

void	print_status(t_vars *vars)
{
	printf("max: %i, piv:%p\n", vars->max, vars->head_pivot);
	print_stack(vars->head_pivot);
	return ;
}

void print_queue(t_queue *queue)
{
	int i;

	ft_putstr_fd(" command: ", STDERR);
	i = 0;
	while(i < queue->depth)
	{
		ft_putnbr_fd(queue->commands[i], STDERR);ft_putstr_fd(", ", STDERR);
		i++;
	}
	ft_putstr_fd("\n", STDERR);
}
