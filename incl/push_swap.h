/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:55:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 18:49:08 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define FAILURE -1

# define TRUE 1
# define FALSE 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define DEPTH_MAX 3
# define SEARCH_MAX 30

# include <stdio.h> // size_t, NULL, printf, perror
# include <unistd.h>
// read, write, close, access, dup, dup2, execve, fork, pipe, unlink
# include <stdlib.h> // size_t, NULL, malloc, free, exit
# include <limits.h> // INT_MAX
# include <errno.h> // errno
# include "libft.h" // libft
# include "push_swap_struct.h"

// push_swap_main.c
void	push_swap_exec(t_vars *vars);
int		main(int argc, char *argv[]);

// push_swap_init.c
t_stack	*push_swap_new_element(void);
t_stack	*push_swap_add_element(t_stack *head, int number);
void	push_swap_vars_init(t_vars *vars);
void	push_swap_stack_init(int argc, char **argv, t_vars *vars);

// push_swap_stack_util.c
int		push_swap_count_stack(t_stack *head);
int		push_swap_is_sorted(t_stack *head);
int		push_swap_is_empty(t_stack *head);
t_pair	*push_swap_copy_pair(t_pair *pair);

// push_swap_stack_valid.c
int		push_swap_valid_input(t_stack *head, int n);
int		push_swap_2stack_compare_wrap(t_stack *head_i, t_stack *head_j);
int		push_swap_pairs_compare_order(t_pair *pair_i, t_pair *pair_j);
int		push_swap_stack_compare_order(t_stack *head_i, t_stack *head_j);
int		push_swap_is_pair_completed(t_pair *pair);

// push_swap_sort_index.c
t_stack	*push_swap_new_copy_element(t_stack *src, \
	t_stack *copy_next, t_stack *copy_prev);
t_stack	*push_swap_copy_stack(t_stack *head);
t_stack	*push_swap_copy_sort(t_stack *head);
int		push_swap_add_index(t_stack *head);

// push_swap_quicksort.c
void	push_swap_push_half(t_vars *vars);
void	push_swap_back_half(t_vars *vars);
void	push_swap_small_sort_pa(t_vars *vars);
void	push_swap_small_sort_ra(t_vars *vars);
void	push_swap_quicksort(t_vars *vars);

// push_swap_step_add.c
// void	push_swap_push_step(t_step *add, t_vars *vars);
void	push_swap_add_step(int int_command, char *command, t_vars *vars);

// push_swap_step_optimize.c
int		push_swap_step_optimize_2step(t_step *head);
int		push_swap_skip_2step(t_step *step);

// push_swap_sort_dfs.c
t_queue	*push_swap_queue_init(t_step *head);
void	push_swap_free_queue(t_queue *queue);
void	push_swap_move_pair(t_pair *pair, int command, int direction);
int		push_swap_move_queue(t_queue *queue, int limit_depth);
int		push_swap_bfs(t_step *head, t_vars *vars);

// push_swap_ops_base_pxsx.c
void	push_swap_pa(t_pair *stack, t_vars *vars);
void	push_swap_pb(t_pair *stack, t_vars *vars);
void	push_swap_sa(t_pair *stack, t_vars *vars);
void	push_swap_sb(t_pair *stack, t_vars *vars);
void	push_swap_ss(t_pair *stack, t_vars *vars);
// push_swap_ops_base_rx.c
void	push_swap_ra(t_pair *stack, t_vars *vars);
void	push_swap_rb(t_pair *stack, t_vars *vars);
void	push_swap_rr(t_pair *stack, t_vars *vars);
// push_swap_ops_base_rrx.c
void	push_swap_rra(t_pair *stack, t_vars *vars);
void	push_swap_rrb(t_pair *stack, t_vars *vars);
void	push_swap_rrr(t_pair *stack, t_vars *vars);
// push_swap_operation.c
void	push_swap_pushes(t_stack *head, t_vars *vars);
void	push_swap_swaps(t_stack *head, int i, t_vars *vars);
void	push_swap_rotates(t_stack *head, int i, t_vars *vars);
void	push_swap_reverse_rotates(t_stack *head, int i, t_vars *vars);
// push_swap_op_utils.c
t_stack	*push_swap_pop(t_stack *head);
void	push_swap_push(t_stack *head, t_stack *new_top);
int		push_swap_pop_pivot(t_vars *vars);
void	push_swap_push_pivot(t_vars *vars);

// push_swap_free.c
void	push_swap_free_temp_args(t_vars *vars);
void	push_swap_free_pair(t_pair *pair);
void	push_swap_free_vars(t_vars *vars);
void	push_swap_free_stack(t_stack *head);
void	push_swap_free_pivot(t_pivot *head);
void	push_swap_free_step(t_step *head);
void	push_swap_free_one_step(t_step *step);

// push_swap_error.c
void	push_swap_error(char *message, t_vars *vars);

// push_swap_print.c
char	*push_swap_get_command_name(int command);
void	push_swap_print_step(t_step *head, t_vars *vars);

// push_swap_print_check.c
void	push_swap_print_stack(t_stack *head);
void	push_swap_print_stack_order(t_stack *head);
void	print_stack(t_pivot	*ptr);
void	print_status(t_vars *vars);
void	print_queue(t_queue *queue);

#endif
