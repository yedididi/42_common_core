/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:30:52 by misukim           #+#    #+#             */
/*   Updated: 2023/03/17 15:38:08 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	to_find_len;
	size_t	i;

	to_find_len = ft_strlen(needle);
	i = 0;
	if (to_find_len == 0)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if ((len - i >= to_find_len) && \
				ft_strncmp(&haystack[i], needle, to_find_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
