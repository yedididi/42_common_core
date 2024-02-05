/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:43:00 by yejlee2           #+#    #+#             */
/*   Updated: 2023/06/27 12:40:54 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	get_pivot(t_info *info)
{
	int	*arr;

	arr = fill_array(info);
	see_if_sorted(arr, info->size_a);
	sort_array(arr, 0, info->size_a - 1, arr[(info->size_a - 1) / 2]);
	info->first_pivot = arr[info->size_a / 3];
	info->second_pivot = arr[(info->size_a * 2) / 3];
	free(arr);
}

int	*fill_array(t_info *info)
{
	int		*arr;
	int		i;
	t_node	*node;

	arr = (int *)malloc(sizeof(int) * info->size_a);
	if (arr == 0)
		error('y');
	i = 0;
	node = info->head_a->rlink;
	while (i < info->size_a)
	{
		arr[i++] = node->data;
		node = node->rlink;
	}
	return (arr);
}

void	sort_array(int *arr, int L, int R, int pivot)
{
	int	left;
	int	right;
	int	temp;

	left = L;
	right = R;
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
	if (L < right)
		sort_array(arr, L, right, arr[(L + R) / 2]);
	if (left < R)
		sort_array(arr, left, R, arr[(L + R) / 2]);
}

void	see_if_sorted(int *arr, int len)
{
	int	i;

	i = 0;
	while (len - 1 > i)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			break ;
	}
	if (i == len - 1)
		error('n');
}
