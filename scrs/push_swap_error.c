/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/11 02:19:00 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_free_stack(t_stack *head)
{
	t_stack	*next;
	t_stack	*delete;

	delete = head->next;
	while (delete != head)
	{
		next = delete->next;
		free(delete);
		delete = next;
	}
	free(delete);
	return ;
}

void	push_swap_error(char *message, t_stack *head_a, \
			t_stack *head_b, void *ptr)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (head_a)
		push_swap_free_stack(head_a);
	if (head_b)
		push_swap_free_stack(head_b);
	if (ptr)
		free(ptr);
	if (errno)
		exit (errno);
	exit (EXIT_FAILURE);
}
