/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:04:12 by misukim           #+#    #+#             */
/*   Updated: 2023/03/27 14:26:30 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);

static int	is_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*return_malloc_copy(int i, int j, char const *s1)
{
	size_t	idx;
	size_t	malloc_len;
	char	*new_str;

	idx = 0;
	malloc_len = j - i;
	new_str = malloc(malloc_len + 1);
	if (!new_str)
		return (0);
	while (i < j)
		new_str[idx++] = s1[i++];
	new_str[idx] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (ft_strdup(""));
	i = 0;
	while ((is_set(set, s1[i]) == 1) && s1[i] != '\0')
		i++;
	j = s1_len;
	while (j > 0 && (is_set(set, s1[j - 1]) == 1))
		j--;
	if (i > j)
		return (ft_strdup(""));
	return (return_malloc_copy(i, j, s1));
}
