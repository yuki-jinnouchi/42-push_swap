/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:55:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/05 07:22:21 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // size_t, NULL, printf, perror
# include <unistd.h>
// read, write, close, access, dup, dup2, execve, fork, pipe, unlink
# include <stdlib.h> // size_t, NULL, malloc, free, exit
# include <limits.h> // INT_MAX
# include <errno.h> // errno
# include "libft.h" // libft

typedef struct s_tack
{
	int				number;
	int				order;
	struct s_tack	*next;
	struct s_tack	*prev;
}	t_stack;

// main
void	push_swap_exec(t_stack *head_a, t_stack *head_b);
void	push_swap_init(t_stack *head_a, t_stack *head_b, int argc, char argv[]);
int		main(int argc, char *argv[]);

// init
t_stack	*push_swap_new_stack();
t_stack	*push_swap_add_stack(t_stack *ptr, int n);
void	push_swap_init(t_stack *head_a, t_stack *head_b, int argc, char argv[]);

// basic operation
t_stack	*push_swap_pop(t_stack *stack);
void	push_swap_push(t_stack *stack, t_stack *target);

// operations
void	push_swap_pushes(t_stack *head_a, t_stack *head_b, int i);
void	push_swap_swaps(t_stack *head_a, t_stack *head_b, int i);
void	push_swap_rotates(t_stack *head_a, t_stack *head_b, int i);
void	push_swap_reverse_rotates(t_stack *head_a, t_stack *head_b, int i);

// error handling
void	push_swap_free_stack(t_stack *list);
void	push_swap_error(char *message, t_stack *head_a, t_stack *head_b, void*ptr);

#endif
