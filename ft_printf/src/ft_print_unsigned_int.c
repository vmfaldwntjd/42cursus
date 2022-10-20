/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:50:18 by ajordan-          #+#    #+#             */
/*   Updated: 2022/08/26 19:31:57 by jchin            ###   ########.fr       */
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

char	*ft_uitoa(unsigned int n)//양의 정수 n을 문자열로 변환하는 메서드
{
	char	*num;
	int		length;

	length = ft_len_of_num(n);//양의 정수의 길이를 구하기
	num = (char *)malloc(sizeof(char) * (length + 1));//문자열을 반환을 할 것이므로 malloc으로 길이 받기
	if (!num)//널가드
		return (0);
	num[length] = '\0';//마지막 자리에는 널 넣기
	while (n != 0)
	{
		num[--length] = n % 10 + 48;//문자 0의 아스키값: 48
		n /= 10;
	}
	return (num);//문자열을 반환
}

int	ft_print_unsigned_int(unsigned int n)//% 뒤에 u를 입력을 받았을 경우
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);// 양의 정수를 문자열로 바꿔줘야 하므로 메서드를 따로 만들어주었다.
		length += ft_print_string(num);
		free(num);
	}
	return (length);
}
