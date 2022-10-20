/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:58:09 by ajordan-          #+#    #+#             */
/*   Updated: 2022/08/26 19:30:54 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_process_for_formats(va_list *args, const char format)//%를 만났을 때의 문자열을 처리하기
{
	int	length;//%뒤의 값의 길이 결과를 반환

	length = 0;
	if (format == 'c')//문자라면
		length += ft_print_char(va_arg(*args, int));//문자를 출력을 하고, 아스키 코드 정수값의 정보로 가변인자에 정수의 정보를 넣어준다.
	else if (format == 's')//문자열이라면
		length += ft_print_string(va_arg(*args, char *));//ft_printf의 ...에서 s에 해당하는 믄자열 인자를 가져오므로 char * 형식으로 입력을 받고 길이 재기
	else if (format == 'p')//포인터라면
		length += ft_print_ptr(va_arg(*args, unsigned long long));//주소의 길이를 재준다.
	else if (format == 'd' || format == 'i')//만약 d이거나 i이면은 즉 정수 관련이면은 정수를 입력 받는다
		length += ft_print_nbr(va_arg(*args, int));//이걸 문자열로 변환해서 길이를 재준다.
	else if (format == 'u')// 양의 정수라면
		length += ft_print_unsigned_int(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')// 16진수의 의미를 가진 x를 입력을 받았다면
		length += ft_print_hex(va_arg(*args, unsigned int), format);//이번엔 format도 같이 넣어준다. 왜냐하면 대소문자에 따라서 출력이 다르기(대문자, 소문자) 때문
	else if (format == '%')//%를 입력받았다면
		length += ft_print_percent();//%를 출력하고 길이를 더해준다.
	return (length);
}

int	ft_printf(const char *str, ...)// 반환값은 출력한 문자열의 길이
{
	int		i;
	va_list	args;// 가변 인자용 변수 선언
	int		length;// 출력할 문자열의 길이 반환

	i = 0;//문자열의 인덱스용 변수
	length = 0;
	va_start(args, str);//시작은 문자열부터
	while (str[i])//문자열을 살피면서
	{
		if (str[i] == '%')//%를 만났다면(d, c, ..)에 따른 포맷 처리
			length += ft_process_for_formats(&args, str[++i]);
		else
			length += ft_print_char(str[i]);//%를 만나지 않으면 문자열의 길이를 그냥 더해준다.
		i++;
	}
	va_end(args);//가변인자 가공이 끝났다는 것을 표시해주기
	return (length);//문자열의 길이를 반환
}
