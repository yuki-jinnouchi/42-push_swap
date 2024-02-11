/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/11 02:19:23 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_count_stack(t_stack *head)
{
	t_stack	*temp;
	int		count;

	temp = head->next;
	count = 0;
	while (temp != head)
	{
		temp = temp->next;
		count ++;
	}
	return (count);
}

void	push_swap_print_stack(t_stack *head)
{
	t_stack	*temp;
	int		n;

	temp = head->next;
	while (temp != head)
	{
		n = temp->number;
		ft_putnbr_fd(n, 1);
		ft_putchar_fd(' ', 1);
		temp = temp->next;
	}
	ft_putchar_fd('\n', 1);
}
