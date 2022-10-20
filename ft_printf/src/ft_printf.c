/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:58:09 by ajordan-          #+#    #+#             */
/*   Updated: 2022/08/27 11:22:17 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_process_for_formats(va_list *args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_print_char(va_arg(*args, int));
	else if (format == 's')
		length += ft_print_string(va_arg(*args, char *));
	else if (format == 'p')
		length += ft_print_ptr(va_arg(*args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		length += ft_print_unsigned_int(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		length += ft_print_percent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			length += ft_process_for_formats(&args, str[++i]);
		else
			length += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
