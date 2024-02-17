/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 16:41:58 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_swap_get_command_name(int command);
void	push_swap_print_step(t_step *head, t_vars *vars);

char *push_swap_get_command_name(int command)
{
	if (command == 1)
		return (ft_strdup("pa\n"));
	if (command == 2)
		return (ft_strdup("pb\n"));
	if (command == 3)
		return (ft_strdup("sa\n"));
	if (command == 4)
		return (ft_strdup("sb\n"));
	if (command == 5)
		return (ft_strdup("ss\n"));
	if (command == 6)
		return (ft_strdup("ra\n"));
	if (command == 7)
		return (ft_strdup("rb\n"));
	if (command == 8)
		return (ft_strdup("rr\n"));
	if (command == 9)
		return (ft_strdup("rra\n"));
	if (command == 10)
		return (ft_strdup("rrb\n"));
	if (command == 11)
		return (ft_strdup("rrr\n"));
	return (NULL);
}

void	push_swap_print_step(t_step *head, t_vars *vars)
{
	t_step *temp;
	char *command;

	temp = head->next;
	while (temp != head)
	{
		command = push_swap_get_command_name(temp->int_command);
		ft_putstr_fd(command, 1);
		// push_swap_print_stack_order(temp->pair->head_a);
		free(command);
		temp = temp->next;
	}
	if (vars != NULL)
	{
		push_swap_free_step(head);
		vars->head_step = NULL;
	}
	return ;
}

/*
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
*/