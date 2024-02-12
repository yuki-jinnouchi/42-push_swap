/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:46:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/12 15:37:00 by yjinnouc         ###   ########.fr       */
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

t_stack	*push_swap_new_element(void)
{
	t_stack	*ptr;

	ptr = (t_stack *) malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->number = 0;
	ptr->order = 0;
	ptr->name = 0;
	ptr->next = ptr;
	ptr->prev = ptr;
	return (ptr);
}

t_stack	*push_swap_add_element(t_stack *head, int number)
{
	t_stack	*new;

	new = push_swap_new_element();
	if (new == NULL)
		return (NULL);
	new->number = number;
	push_swap_push(head, new);
	return (new);
}

void	push_swap_init(int argc, char *argv[], t_vars *vars)
{
	int	arg_count;
	int	number;

	vars->head_a = push_swap_new_element();
	vars->head_b = push_swap_new_element();
	if (vars->head_a == NULL || vars->head_b == NULL)
		push_swap_error("head malloc error", vars);
	vars->head_a->name = 'a';
	vars->head_b->name = 'b';
	arg_count = argc - 1;
	while (arg_count > 0)
	{
		number = ft_atoi(argv[arg_count]);
		if (push_swap_valid_input(vars->head_a, number) == FALSE)
			push_swap_error("input valid error", vars);
		if (push_swap_add_element(vars->head_a, number) == NULL)
			push_swap_error("elem malloc error", vars);
		arg_count--;
	}
	return ;
}
