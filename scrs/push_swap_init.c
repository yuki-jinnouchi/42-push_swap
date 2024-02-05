/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/05 07:20:36 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
typedef struct s_tack
{
	int				*number;
	int				*order;
	struct s_tack	*next;
	struct s_tack	*prev;
}	t_stack;
*/

t_stack	*push_swap_new_stack()
{
	t_stack	*ptr;

	ptr = (t_stack *) malloc(sizeof(ptr));
	if (!ptr)
		return (NULL);
	ptr->number = NULL;
	ptr->order = NULL;
	ptr->next = ptr;
	ptr->prev = ptr;

	return (ptr);
}

t_stack	*push_swap_add_stack(t_stack *ptr, int n)
{
	t_stack	*new;
	t_stack	*temp;

	new = push_swap_new_stack();
	if (new == NULL)
		push_swap_error("init error", ptr, NULL, new);
	new -> number = n;
	temp = ptr -> prev;
	temp -> next = new;
	ptr-> prev = new;
	// if (ptr->order == NULL)
	// 	new->order = 0;
	// else
	// 	new->order = ptr->order + 1;
	new -> prev = temp;
	new -> next = ptr;
	return (new);
}

void	push_swap_init(t_stack *head_a, t_stack *head_b, int argc, char argv[])
{
	int		i;
	int		n;
	t_stack	*temp;

	i = 1;
	temp = head_a;
	while (i <= argc)
	{
		n = ft_atoi(argv[i]);
		if (n == 0)
			push_swap_error("atoi error", head_a, head_b, NULL);
		temp = push_swap_add_stack(temp, n);
		if (temp == NULL)
			push_swap_error("init malloc error", head_a, head_b, NULL);
		i++;
	}
	return ;
}