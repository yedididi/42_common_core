/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:38:30 by misukim           #+#    #+#             */
/*   Updated: 2023/03/31 01:14:57 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		chr;

	i = 0;
	str = (const unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (*(str + i) == chr)
			return ((unsigned char *)(str + i));
		i++;
	}
	return (0);
}
