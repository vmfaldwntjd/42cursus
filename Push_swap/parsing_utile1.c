/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utile1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:47:46 by kko               #+#    #+#             */
/*   Updated: 2022/10/06 22:11:48 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnum(int **ret, int *j, char *argv)
{
	int		i;
	int		k;
	int		c;
	char	**split;

	i = *j;
	c = 0;
	k = ft_wordc(argv, ' ');
	split = ft_split(argv, ' ');
	while (k > 0)
	{
		ret[0][i] = atoi(split[c]);
		i++;
		k--;
		c++;
	}
	*j = i;
}

int	*make_arr(int argc, char **argv, int size)
{
	int	*ret;
	int	i;
	int	j;

	i = 1;
	j = 0;
	ret = (int *)malloc(sizeof(int) * (size + 1));
	while (i < argc)
	{
		if (ft_check_array(argv[i]) == 0)
			ret[j++] = ft_atoi(argv[i]);
		else if (ft_check_array(argv[i]) == 1)
			ft_putnum (&ret, &j, argv[i]);
		i++;
	}
	i = 0;
	return (ret);
}

void	quick(int *arr, int L, int R)
{
	int	left;
	int	right;
	int	pivot;

	left = L;
	right = R;
	pivot = arr[(L + R) / 2];
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			ft_swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	if (L < right)
		quick(arr, L, right);
	if (left < R)
		quick(arr, left, R);
}

void	ft_sort(int *sorted, int size, t_deque *info)
{
	int	*tmp;
	int	tmp1;
	int	tmp2;

	tmp = sorted;
	quick(tmp, 0, size - 1);
	err_overlap(tmp, size);
	info->sorted = tmp;
	tmp1 = info->size_a;
	tmp2 = 0;
	while (tmp1--)
	{
		if (info->arr[tmp1] == info->sorted[tmp1])
			tmp2++;
	}
	if (tmp2 == info->size_a)
		exit(0);
}

void	parsing(int argc, char **argv, t_deque *info)
{
	int	*arr;
	int	size;
	int	*sorted;

	size = figures(argc, argv);
	if (size <= 0)
		err(1);
	ft_check(argc, argv);
	info->size_a = size;
	info->size = size;
	info->size_b = 0;
	arr = make_arr(argc, argv, size);
	info->arr = arr;
	sorted = make_arr(argc, argv, size);
	ft_sort(sorted, size, info);
}
