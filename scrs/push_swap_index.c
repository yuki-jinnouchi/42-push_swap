/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 12:35:01 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_swap_new_copy_element(t_stack *src_temp, \
	t_stack *copy_next, t_stack *copy_prev);
t_stack	*push_swap_copy_stack(t_stack *head);
t_stack	*push_swap_copy_sort(t_stack *head);
int		push_swap_add_index(t_stack *head);

t_stack	*push_swap_new_copy_element(t_stack *src_temp, \
	t_stack *copy_next, t_stack *copy_prev)
{
	t_stack	*ptr;

	ptr = (t_stack *) malloc(sizeof(t_stack) + 1);
	if (!ptr)
		return (NULL);
	ptr->number = src_temp->number;
	ptr->order = src_temp->order;
	ptr->next = copy_next;
	ptr->prev = copy_prev;
	ptr->prev->next = ptr;
	return (ptr);
}

t_stack	*push_swap_copy_stack(t_stack *head)
{
	t_stack	*copy_head;
	t_stack	*src_temp;
	t_stack	*copy_temp;
	t_stack	*copy_prev;

	copy_head = (t_stack *) malloc(sizeof(t_stack));
	if (!copy_head)
		return (NULL);
	copy_head->name = head->name;
	copy_head->prev = copy_head;
	copy_head->next = copy_head;
	copy_prev = copy_head;
	src_temp = head->next;
	while (src_temp != head)
	{
		copy_temp = push_swap_new_copy_element(src_temp, copy_head, copy_prev);
		if (copy_temp == NULL)
		{
			push_swap_free_stack(copy_head);
			return (NULL);
		}
		copy_prev = copy_temp;
		src_temp = src_temp->next;
	}
	copy_head->prev = copy_prev;
	return (copy_head);
}

t_stack	*push_swap_copy_sort(t_stack *head)
{
	t_stack	*copy_head;
	t_stack	*temp;
	t_stack	*picked;
	int		i;

	copy_head = push_swap_copy_stack(head);
	if (copy_head == NULL)
		return (NULL);
	temp = copy_head->next;
	while (push_swap_is_sorted(copy_head) == FALSE)
	{
		temp = copy_head->next;
		while (temp->next != copy_head)
		{
			if (temp->number > temp->next->number)
			{
				picked = push_swap_pop(temp);
				push_swap_push(temp->prev, picked);
			}
			else
				temp = temp->next;
		}
	}
	return (copy_head);
}

int	push_swap_add_index(t_stack *head)
{
	t_stack	*sorted_copy_head;
	t_stack	*temp_src_temp;
	t_stack	*temp_copy;
	int		count;

	sorted_copy_head = push_swap_copy_sort(head);
	if (sorted_copy_head == NULL)
		return (FAILURE);
	temp_src_temp = head->next;
	temp_copy = sorted_copy_head;
	while (temp_src_temp != head)
	{
		count = 1;
		temp_copy = sorted_copy_head->next;
		while (temp_src_temp->order == 0 && temp_copy != sorted_copy_head)
		{
			if (temp_src_temp->number == temp_copy->number)
				temp_src_temp->order = count;
			temp_copy = temp_copy->next;
			count++;
		}
		temp_src_temp = temp_src_temp->next;
	}
	push_swap_free_stack(sorted_copy_head);
	return (SUCCESS);
}
