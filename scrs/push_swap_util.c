/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/11 06:00:54 by yjinnouc         ###   ########.fr       */
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

	temp = head->next;
	while (temp != head)
	{
		ft_putnbr_fd(temp->number, 1);
		ft_putchar_fd(' ', 1);
		temp = temp->next;
	}
	ft_putchar_fd('\n', 1);
}

int	push_swap_is_sorted(t_stack *head)
{
	t_stack	*ptr;
	int		number;

	ptr = head->next;
	number = ptr->number;
	while (ptr->next->number != 0)
	{
		if (number > ptr->next->number)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

int	push_swap_is_empty(t_stack *head)
{
	if (head->next == head)
		return (TRUE);
	return (FALSE);
}
