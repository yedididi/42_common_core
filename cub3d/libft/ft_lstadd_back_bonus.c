/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:18 by misukim           #+#    #+#             */
/*   Updated: 2023/03/31 15:55:07 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	i = *lst;
	if (new != NULL)
	{
		while (i->next != NULL)
		{
			i = i->next;
		}
		i->next = new;
	}
}
