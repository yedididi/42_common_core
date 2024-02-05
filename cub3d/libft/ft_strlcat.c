/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:45:22 by misukim           #+#    #+#             */
/*   Updated: 2023/03/17 15:32:48 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	d_idx;
	size_t	s_idx;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	d_idx = dst_len;
	s_idx = 0;
	if (size == 0 || size <= dst_len)
		return (src_len + size);
	while (src[s_idx] && s_idx + dst_len + 1 < size)
	{
		dest[d_idx] = src[s_idx];
		d_idx++;
		s_idx++;
	}
	dest[d_idx] = '\0';
	return (dst_len + src_len);
}
