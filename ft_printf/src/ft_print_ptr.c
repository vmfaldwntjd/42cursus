/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:20:43 by ajordan-          #+#    #+#             */
/*   Updated: 2022/08/26 15:38:16 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num)//intptr_t은 포인터의 주소를 저장하기 위한 데이터 타입이다.->다른 환경으로 이식이 가능하다는 장점이 있다.
//일반 포인터와는 다르게 intptr_t *p = (intptr_t)&num과 같은 방식으로 캐스팅을 통해서 저장한다.
{
	if (num >= 16)//포인터의 주소는 16진법으로 나타내며 저장을 할 것이다.
	{
		ft_put_ptr(num / 16);//재귀 용법을 통해서 저장을 진행
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);// 10 이상이면 a부터 가는 것으로 처리
	}
}

int	ft_print_ptr(unsigned long long ptr)//%p를 받기용 메서드
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)//포인터가 0이라면
		length += write(1, "0", 1);//그대로 0을 출력하며 길이를 추가
	else
	{
		ft_put_ptr(ptr);//ptr은 정수이다.
		length += ft_ptr_len(ptr);// 포인터의 길이도 재주기
	}
	return (length);
}
