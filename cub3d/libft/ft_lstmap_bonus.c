/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:44:24 by misukim           #+#    #+#             */
/*   Updated: 2023/03/30 18:44:25 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_new;
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	head_new = NULL;
	new = NULL;
	tmp = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new = ft_lstnew(tmp);
		if (new == NULL)
		{
			ft_lstclear(&new, del);
			ft_lstclear(&head_new, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&head_new, new);
		lst = lst->next;
	}
	return (head_new);
}
