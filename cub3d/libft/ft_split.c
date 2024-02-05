/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:19:14 by misukim           #+#    #+#             */
/*   Updated: 2023/11/22 16:20:17 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_delimiter(char const str, char delimiter)
{
	if ((str == delimiter) || (str == '\0'))
		return (1);
	return (0);
}

static char	*new_strcpy(char *dest, const char *src, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// static int	free_array(char **arr, size_t arr_idx)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i <= arr_idx)
// 	{
// 		free(arr[i]);
// 		arr[i] = 0;
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }

static int	free_array(char **arr, size_t arr_idx)
{
	size_t	i;

	i = 0;
	(void)arr_idx;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	free(arr);
	return (0);
}

static int	set_array(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	arr_idx;

	i = 0;
	arr_idx = 0;
	while (s[i] != '\0')
	{
		if (is_delimiter(s[i], c))
			i++;
		else
		{
			j = 0;
			while (!is_delimiter(s[i + j], c))
				j++;
			arr[arr_idx] = malloc(j + 1);
			if (!arr[arr_idx])
				return (free_array(arr, arr_idx));
			new_strcpy(arr[arr_idx], &s[i], j);
			i += j;
			arr_idx++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_num;
	size_t	i;
	char	**arr;

	word_num = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!is_delimiter(s[i], c) && is_delimiter(s[i + 1], c))
			word_num++;
		i++;
	}
	arr = malloc(sizeof(char *) * (word_num + 1));
	if (!arr)
		return (0);
	if (set_array(s, c, arr) == 0)
		return (0);
	arr[word_num] = 0;
	return (arr);
}
