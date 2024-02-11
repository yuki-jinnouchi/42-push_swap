/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/11 02:19:07 by yjinnouc         ###   ########.fr       */
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

t_stack	*push_swap_new_stack(void)
{
	t_stack	*ptr;

	ptr = (t_stack *) malloc(sizeof(t_stack) + 1);
	if (!ptr)
		return (NULL);
	ptr->number = 0;
	ptr->order = 0;
	ptr->next = ptr;
	ptr->prev = ptr;
	return (ptr);
}

t_stack	*push_swap_add_stack(t_stack *head, int n)
{
	t_stack	*new;

	new = push_swap_new_stack();
	if (new == NULL)
		push_swap_error("init error", head, NULL, new);
	new->number = n;
	push_swap_push(head, new);
	return (new);
}

void	push_swap_init(t_stack *head_a, int argc, char *argv[])
{
	int		i;
	int		n;
	t_stack	*temp;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n == 0)
			push_swap_error("atoi error", head_a, NULL, NULL);
		temp = push_swap_add_stack(head_a, n);
		if (temp == NULL)
			push_swap_error("init malloc error", head_a, NULL, NULL);
		// ft_putnbr_fd(temp->number, 1);
		// ft_putstr_fd("\n", 1);
		i++;
	}
	return ;
}
