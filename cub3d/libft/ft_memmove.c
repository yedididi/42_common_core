/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:17:51 by misukim           #+#    #+#             */
/*   Updated: 2023/03/21 16:28:49 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	if (src < dst)
	{
		while (len > 0)
		{
			i = len - 1;
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			--len;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			++i;
		}
	}
	return (dst);
}
