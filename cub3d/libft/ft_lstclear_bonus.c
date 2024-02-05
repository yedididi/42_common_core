/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:50:54 by misukim           #+#    #+#             */
/*   Updated: 2023/03/31 15:57:30 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*next;

	i = *lst;
	next = NULL;
	while (i != NULL)
	{
		next = i->next;
		del(i->content);
		free(i);
		i = next;
	}
	*lst = NULL;
}
