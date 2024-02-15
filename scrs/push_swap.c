/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/15 15:51:48 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc < 2)
		push_swap_error("argument must be more than 1", NULL);
	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		push_swap_error("vars malloc error", vars);
	push_swap_init(argc, argv, vars);
	push_swap_exec(vars);
	push_swap_free_vars(vars);
	return (SUCCESS);
}
