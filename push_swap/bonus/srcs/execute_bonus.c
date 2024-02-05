/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:03:30 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/28 15:14:19 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

void	execute(t_info *info)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		if (command_chk(tmp, info) == 0)
			error('y');
		free(tmp);
		tmp = get_next_line(0);
	}
}

int	command_chk(char *tmp, t_info *info)
{
	if (ft_strncmp(tmp, "sa\n", ft_strlen(tmp)) == 0)
		return (execute_sa(info));
	if (ft_strncmp(tmp, "sb\n", ft_strlen(tmp)) == 0)
		return (execute_sb(info));
	if (ft_strncmp(tmp, "ss\n", ft_strlen(tmp)) == 0)
		return (execute_ss(info));
	if (ft_strncmp(tmp, "pa\n", ft_strlen(tmp)) == 0)
		return (execute_pa(info));
	if (ft_strncmp(tmp, "pb\n", ft_strlen(tmp)) == 0)
		return (execute_pb(info));
	if (ft_strncmp(tmp, "ra\n", ft_strlen(tmp)) == 0)
		return (execute_ra(info));
	if (ft_strncmp(tmp, "rb\n", ft_strlen(tmp)) == 0)
		return (execute_rb(info));
	if (ft_strncmp(tmp, "rr\n", ft_strlen(tmp)) == 0)
		return (execute_rr(info));
	if (ft_strncmp(tmp, "rra\n", ft_strlen(tmp)) == 0)
		return (execute_rra(info));
	if (ft_strncmp(tmp, "rrb\n", ft_strlen(tmp)) == 0)
		return (execute_rrb(info));
	if (ft_strncmp(tmp, "rrr\n", ft_strlen(tmp)) == 0)
		return (execute_rrr(info));
	return (0);
}

int	execute_rrr(t_info *info)
{
	execute_rra(info);
	execute_rrb(info);
	return (11);
}
