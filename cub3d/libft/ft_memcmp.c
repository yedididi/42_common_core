/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:17:39 by misukim           #+#    #+#             */
/*   Updated: 2023/03/31 01:12:08 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;
	size_t				i;

	p_s1 = s1;
	p_s2 = s2;
	i = 0;
	while (i < n)
	{
		if (*(p_s1 + i) != *(p_s2 + i))
			return ((int)(*(p_s1 + i) - *(p_s2 + i)));
		i++;
	}
	return (0);
}
