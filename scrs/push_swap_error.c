/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/16 18:36:11 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_error(char *message, t_vars *vars);

void	push_swap_error(char *message, t_vars *vars)
{
	ft_putstr_fd("Error\n", STDERR);
	ft_putstr_fd(message, STDERR);
	ft_putchar_fd('\n', STDERR);
	push_swap_free_vars(vars);
	if (errno)
		exit (errno);
	exit (EXIT_FAILURE);
}
