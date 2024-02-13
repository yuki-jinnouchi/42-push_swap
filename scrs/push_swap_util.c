/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 08:50:03 by yjinnouc         ###   ########.fr       */
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
}

int	push_swap_is_sorted(t_stack *head)
{
	t_stack	*ptr;

	ptr = head->next;
	while (ptr->next != head)
	{
		if (ptr->number >= ptr->next->number)
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

/*valid not 0 and non duplicated*/
int	push_swap_valid_input(t_stack *head, int n)
{
	t_stack *temp;

	if (n == 0)
		return(FALSE);
	temp = head->next;
	while (temp != head)
	{
		if (temp->number == n)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}
