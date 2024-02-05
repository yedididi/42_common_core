/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:16:55 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/27 14:05:28 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "../../libft/libft.h"

typedef struct s_node
{
	struct s_node	*llink;
	int				data;
	struct s_node	*rlink;
}	t_node;

typedef struct s_info
{
	int				size_a;
	struct s_node	*head_a;
	struct s_node	*tail_a;
	int				size_b;
	struct s_node	*head_b;
	struct s_node	*tail_b;
	int				first_pivot;
	int				second_pivot;
}	t_info;

void		init_list(t_info *info);
t_node		*create_newnode(int value);
void		add_newnode(int value, t_info *info);
void		search_for_dup(int value, t_info info);

void		error(int c);
const char	*before_atoi(const char *str);
long long	ft_atoi(const char *str);
void		free_node(t_node *node);
int			ft_isnum(int num);

void		fill_stack(int argc, char *argv[], t_info *info);
int			check_for_sp(char *str);
void		fill_index_sp(char *str, t_info *info);

void		get_pivot(t_info *info);
int			*fill_array(t_info *info);
void		sort_array(int *arr, int L, int R, int pivot);
void		see_if_sorted(int *arr, int len);

void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);
void		pa(t_info *info);
void		pb(t_info *info);
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

void		start_sorting(t_info *info);
void		sort_two_nbrs(t_info *info);
void		sort_three_nbrs(t_info *info);
void		sort_more_nbrs(t_info *info);
void		make_three_parts(t_info *info);

void		be_greedy(t_info *info);
void		rotate_both(int *mvcount_a, int *mvcount_b, t_info *info);
void		rotate_a(int mvcount_a, t_info *info);
void		rotate_b(int mvcount_b, t_info *info);
void		last_rotate(t_info *info);

void		calculate_mv(int *mvcount_a, int *mvcount_b, t_info *info);
int			calculate_mv_a(t_info *info, t_node *node);
int			calculate_mv_b(t_info *info, int i);
int			min_value_of_a(t_info *info);
int			max_value_of_a(t_info *info);

int			calculate_mv_min(t_info *info);
int			calculate_mv_max(t_info *info);
int			calculate_mv_rest(int num, t_info *info);
int			compare(int mvcount_a, int mvcount_b, int tmp_a, int tmp_b);

void		free_two_dim_arr(char **tmp);
void		free_stack_ab(t_node *node);

#endif