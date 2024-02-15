/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/15 16:33:41 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_print_step(t_step *head, t_vars *vars);
void	push_swap_print_stack(t_stack *head);
void	push_swap_print_stack_order(t_stack *head);
void	print_stack(t_pivot	*ptr);
void	print_status(t_vars *vars);

void	push_swap_print_step(t_step *head, t_vars *vars)
{
	t_step *temp;

	temp = head->next;
	while (temp != head)
	{
		ft_putstr_fd(temp->command, 1);
		temp = temp->next;
	}
	push_swap_free_step(head);
	vars->head_step = NULL;
	return ;
}

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
