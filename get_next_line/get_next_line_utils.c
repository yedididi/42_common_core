/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:13:02 by yejlee2           #+#    #+#             */
/*   Updated: 2022/12/08 12:03:22 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*return_str;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (return_str == 0)
		return (0);
	while (*s1)
		return_str[i++] = *s1++;
	while (*s2)
		return_str[i++] = *s2++;
	return_str[i] = '\0';
	return (return_str);
}

char	*ft_strndup(const char *s1, int byte)
{
	char	*dest;
	int		i;

	i = 0;
	if (byte == 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * (byte + 1));
	if (dest == 0)
		return (0);
	while (s1[i] && byte)
	{
		dest[i] = s1[i];
		i++;
		byte--;
	}
	dest[i] = '\0';
	return (dest);
}
