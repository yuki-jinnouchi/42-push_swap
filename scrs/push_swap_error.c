/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/05 06:32:43 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_free_stack(t_stack *list)
{
	t_stack	*temp;

	temp = list -> next;
	while(temp != list)
	{
		temp = list->next;
		free(list);
	}
	return ;
}

void	push_swap_error(char *message, t_stack *head_a, t_stack *head_b, void*ptr)
{
	ft_putstr_fd("push_swap: ", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (head_a != NULL)
		push_swap_free_stack(head_a);
	if (head_b != NULL)
		push_swap_free_stack(head_b);
	if (errno)
		exit (errno);
	exit (EXIT_FAILURE);
}