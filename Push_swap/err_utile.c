/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:48:38 by kko               #+#    #+#             */
/*   Updated: 2022/10/06 20:47:59 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\n", 1);
	else if (i == 2)
		ft_putstr_fd("Error\n", 1);
	else if (i == 3)
		ft_putstr_fd("Error\n", 1);
	else if (i == 4)
		ft_putstr_fd("Error\n", 1);
	else if (i == 5)
		ft_putstr_fd("Error\n", 1);
	else if (i == 6)
		ft_putstr_fd("Error\n", 1);
	else if (i == 7)
		ft_putstr_fd("Error\n", 1);
	exit (0);
}

void	err_overlap(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (size-- > 1)
	{
		j = i + 1;
		if (arr[i] == arr[j])
			err(2);
		i++;
	}
}

void	ft_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = ft_check_array(argv[i]);
		if (j == 0)
			ft_check_array2(argv[i]);
		else if (j == 1)
			ft_check_array3(argv[i]);
		i++;
	}
}

void	ft_check_array2(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && flag == 1)
			err(3);
		else if (s[i] == '-' || s[i] == '+')
			flag = 1;
		else if (!ft_isdigit(s[i]))
			err(3);
		i++;
	}
}

void	ft_check_array3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && \
		str[i] != '-' && str[i] != '+')
			err(5);
		i++;
	}
}
