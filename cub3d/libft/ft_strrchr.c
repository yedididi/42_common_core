/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:20:21 by misukim           #+#    #+#             */
/*   Updated: 2023/03/27 14:20:41 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			tmp = (char *)s;
		s++;
	}
	if (*s == (char)c)
		tmp = (char *)s;
	return (tmp);
}
