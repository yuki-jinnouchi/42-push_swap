/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:55:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/11 05:49:13 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define FAILURE -1

# define TRUE 1
# define FALSE 0

# include <stdio.h> // size_t, NULL, printf, perror
# include <unistd.h>
// read, write, close, access, dup, dup2, execve, fork, pipe, unlink
# include <stdlib.h> // size_t, NULL, malloc, free, exit
# include <limits.h> // INT_MAX
# include <errno.h> // errno
# include "libft.h" // libft

typedef struct s_stack
{
	int				number;
	int				order;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// push_swap_main.c
void	push_swap_exec(t_stack *head_a, t_stack *head_b);
int		main(int argc, char *argv[]);

// push_swap_init.c
t_stack	*push_swap_new_element(void);
t_stack	*push_swap_add_element(t_stack *head, int n);
void	push_swap_init(t_stack *head_a, int argc, char *argv[]);

// push_swap_op_utils.c
t_stack	*push_swap_pop(t_stack *head);
void	push_swap_push(t_stack *head, t_stack *new_top);

// push_swap_operation.c
void	push_swap_pushes(t_stack *head_a, t_stack *head_b, int i);
void	push_swap_swaps(t_stack *head_a, t_stack *head_b, int i);
void	push_swap_rotates(t_stack *head_a, t_stack *head_b, int i);
void	push_swap_reverse_rotates(t_stack *head_a, t_stack *head_b, int i);

// push_swap_util.c
int		push_swap_count_stack(t_stack *head);
void	push_swap_print_stack(t_stack *head);
int		push_swap_is_sorted(t_stack *head);
int		push_swap_is_empty(t_stack *head);

// push_swap_sort_index.c
t_stack	*push_swap_new_copy_element(t_stack *src, \
			t_stack *copy_head, t_stack *copy_prev);
t_stack *push_swap_copy_stack(t_stack *head);
t_stack	*push_swap_copy_sort(t_stack *head);
int	push_swap_add_index(t_stack *head);

// push_swap_sort_exec.c
void	push_swap_exec(t_stack *head_a, t_stack *head_b);

// push_swap_error.c
void	push_swap_free_stack(t_stack *head);
void	push_swap_error(char *message, t_stack *head_a, \
			t_stack *head_b, void*ptr);

#endif
