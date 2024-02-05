/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:15:34 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/27 14:29:08 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "../../get_next_line/get_next_line.h"
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
}	t_info;

void		error(int num);
int			check(t_info *info);

void		init_list(t_info *info);
t_node		*create_newnode(int value);
void		add_newnode(int value, t_info *info);
void		search_for_dup(int value, t_info info);

void		fill_stack(int argc, char *argv[], t_info *info);
int			check_for_sp(char *str);
void		fill_index_sp(char *str, t_info *info);

void		execute(t_info *info);
int			command_chk(char *tmp, t_info *info);

int			execute_sa(t_info *info);
int			execute_sb(t_info *info);
int			execute_ss(t_info *info);
int			execute_pa(t_info *info);
int			execute_pb(t_info *info);
int			execute_ra(t_info *info);
int			execute_rb(t_info *info);
int			execute_rr(t_info *info);
int			execute_rra(t_info *info);
int			execute_rrb(t_info *info);
int			execute_rrr(t_info *info);

void		free_two_dim_arr(char **str);
void		free_stack_ab(t_node *node);
const char	*before_atoi(const char *str);
long long	ft_atoi(const char *str);
int			ft_isnum(int num);

#endif