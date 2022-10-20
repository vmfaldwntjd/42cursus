/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utile1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:59:58 by kko               #+#    #+#             */
/*   Updated: 2022/10/06 19:49:33 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_deque *info)
{
	ft_swap(&info->top_a->val, &info->top_a->next->val);
	ft_putstr_fd("sa\n", 1);
}

void	ft_pb(t_deque *info)
{
	t_node	*tmp;

	if (info->size_a < 4)
		return ;
	if (info->size_b == 0)
		ft_b(info);
	else
		insert_head_b(info, info->top_a->val);
	tmp = info->top_a->next;
	free(info->top_a);
	info->top_a = tmp;
	info->top_a->prev = 0;
	(info->size_a)--;
	(info->size_b)++;
	ft_putstr_fd("pb\n", 1);
}

void	ft_ra(t_deque *info)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (info->size_a == 1)
		return ;
	tmp = info->top_a;
	tmp1 = info->top_a->next;
	tmp1->prev = 0;
	info->top_a = tmp1;
	info->bottom_a->next = tmp;
	tmp->next = 0;
	tmp->prev = info->bottom_a;
	info->bottom_a = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rra(t_deque *info)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (info->size_a == 1)
		return ;
	tmp = info->bottom_a;
	tmp1 = info->bottom_a->prev;
	tmp1->next = 0;
	tmp->next = info->top_a;
	tmp->prev = 0;
	info->top_a->prev = tmp;
	info->top_a = tmp;
	info->bottom_a = tmp1;
	ft_putstr_fd("rra\n", 1);
}
