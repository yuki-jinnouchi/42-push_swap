/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:55:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/17 18:46:41 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

typedef struct s_stack
{
	int				number;
	int				order;
	char			name;
	struct s_stack	*opposite;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_pair
{
	struct s_stack	*head_a;
	struct s_stack	*head_b;
}					t_pair;

typedef struct s_pivot
{
	int				max;
	struct s_pivot	*next;
}					t_pivot;

typedef struct s_step
{
	int				int_command;
	char			*command;
	struct s_pair	*pair;
	struct s_step	*next;
	struct s_step	*prev;
}					t_step;

typedef struct s_queue
{
	int				*commands;
	int				depth;
	int				depth_basis;
	struct s_stack	*copy_head_a;
	struct s_pair	*pair;
	struct s_step	*root_head_a;
	struct s_pair	*root_pair;
	int				find_length;
}					t_queue;

typedef struct s_vars
{
	int				arg_size;
	struct s_pair	*pair;
	struct s_stack	*head_a;
	struct s_stack	*head_b;
	struct s_pivot	*head_pivot;
	int				min;
	int				avg;
	int				max;
	int				dir;
	int				n_step;
	struct s_step	*head_step;
	char			**arg_temp;
}					t_vars;

#endif
