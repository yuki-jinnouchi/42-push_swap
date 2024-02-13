/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:03:01 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 21:03:33 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_pushes(t_stack *head);
void	push_swap_swaps(t_stack *head, int i);
void	push_swap_rotates(t_stack *head, int i);
void	push_swap_reverse_rotates(t_stack *head, int i);

/*pa (push a): Take the first element at the top of b
and put it at the top of a. Do nothing if b is empty.*/
/*pb (push b): Take the first element at the top of a
and put it at the top of b. Do nothing if a is empty.*/

void	push_swap_pushes(t_stack *head)
{
	t_stack	*temp;

	temp = push_swap_pop(head->opposite);
	push_swap_push(head, temp);
	ft_putstr_fd("p", 1);
	ft_putchar_fd(head->name, 1);
	ft_putstr_fd("\n", 1);
}

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
/*sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
/*ss : sa and sb at the same time.*/

void	push_swap_swaps(t_stack *head, int i)
{
	t_stack	*temp;

	temp = push_swap_pop(head);
	push_swap_push(head -> next, temp);
	if (i == 1)
	{
		temp = push_swap_pop(head->opposite);
		push_swap_push(head->opposite->next, temp);
	}
	ft_putstr_fd("s", 1);
	if (i == 0)
		ft_putchar_fd(head->name, 1);
	if (i == 1)
		ft_putchar_fd('s', 1);
	ft_putstr_fd("\n", 1);
}

/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
/*rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
/*rr : ra and rb at the same time*/

void	push_swap_rotates(t_stack *head, int i)
{
	t_stack	*temp;

	temp = push_swap_pop(head);
	push_swap_push(head -> prev, temp);
	if (i == 1)
	{
		temp = push_swap_pop(head->opposite);
		push_swap_push(head->opposite-> prev, temp);
	}
	ft_putstr_fd("r", 1);
	if (i == 0)
		ft_putchar_fd(head->name, 1);
	if (i == 1)
		ft_putchar_fd('r', 1);
	ft_putstr_fd("\n", 1);
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
/*rrr : rra and rrb at the same time.*/

void	push_swap_reverse_rotates(t_stack *head, int i)
{
	t_stack	*temp;

	temp = push_swap_pop(head->prev->prev);
	push_swap_push(head, temp);
	if (i == 1)
	{
		temp = push_swap_pop(head->opposite->prev-> prev);
		push_swap_push(head->opposite, temp);
	}
	ft_putstr_fd("rr", 1);
	if (i == 0)
		ft_putchar_fd(head->name, 1);
	if (i == 1)
		ft_putchar_fd('r', 1);
	ft_putstr_fd("\n", 1);
}
