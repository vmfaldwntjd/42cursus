/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utile2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:31:18 by kko               #+#    #+#             */
/*   Updated: 2022/10/06 21:20:31 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	ft_check_minus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
		{
			ft_putstr_fd("Error", 1);
			exit(0);
		}
		i++;
	}
}

int	ft_check_array(char *s)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			++space;
		else if (ft_isdigit(s[i]) && space == 1)
			return (1);
		if ((s[i] == '-' || s[i] == '+') && !(ft_isdigit(s[i + 1])))
			err(6);
		i++;
	}
	return (0);
}

int	figures(int argc, char **argv)
{
	int	i;
	int	ret;
	int	state;

	i = 1;
	ret = 0;
	state = 0;
	while (i < argc)
	{
		state = ft_check_array(argv[i]);
		if (state == 0)
			ret++;
		else if (state == 1)
		{
			ft_check_minus(argv[i]);
			ret += ft_wordc(argv[i], ' ');
		}
		i++;
	}
	return (ret);
}

int	ft_wordc(const char *s, char c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			ret++;
		i++;
	}
	if (i == 0)
		return (0);
	return (ret);
}
