/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/11 01:52:42 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (argc < 1)
		push_swap_error("argument must be more than 2", NULL, NULL, NULL);
	if (argc == 1)
		return (0);
	head_a = push_swap_new_stack();
	push_swap_init(head_a, argc, argv);
	head_b = push_swap_new_stack();
	// push_swap_exec(head_a, head_b);
	push_swap_print_stack(head_a);
	push_swap_free_stack(head_a);
	push_swap_free_stack(head_b);
	return (0);
}
