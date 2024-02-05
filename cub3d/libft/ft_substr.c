/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:39:34 by misukim           #+#    #+#             */
/*   Updated: 2023/03/24 22:20:00 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*substr;

	s_len = ft_strlen(s);
	i = 0;
	if (len == 0 || s_len == 0 || s_len <= start)
		return (ft_strdup(""));
	if (start + len <= s_len)
		substr = malloc(len + 1);
	else
		substr = malloc((s_len - start) + 1);
	if (!substr)
		return (0);
	while (i < len && i < s_len - start)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
