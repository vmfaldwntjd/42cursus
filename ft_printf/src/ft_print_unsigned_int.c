/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:50:18 by ajordan-          #+#    #+#             */
/*   Updated: 2022/08/27 11:23:16 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_len_of_num(unsigned	int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		length++;
		num = num / 10;
	}
	return (length);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		length;

	length = ft_len_of_num(n);
	num = (char *)malloc(sizeof(char) * (length + 1));
	if (!num)
		return (0);
	num[length] = '\0';
	while (n != 0)
	{
		num[--length] = n % 10 + 48;
		n /= 10;
	}
	return (num);
}

int	ft_print_unsigned_int(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		length += ft_print_string(num);
		free(num);
	}
	return (length);
}
