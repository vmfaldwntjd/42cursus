/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:46:33 by kko               #+#    #+#             */
/*   Updated: 2022/10/06 20:53:10 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_a(t_deque *info)
{
	int		i;
	int		j;

	ft_a(info);
	i = info->size_a;
	j = 1;
	while (i > j)
	{
		insert_tail_a(info, info->arr[j]);
		j++;
	}
}

void	ft_stack(t_deque *info)
{
	make_a(info);
	if (info->size_a == 3)
	{
		case_num3_a(info);
		exit(0);
	}
	else if (info->size_a == 5)
	{
		case_num5_a(info);
		exit(0);
	}
}

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
