/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:40:58 by ajordan-          #+#    #+#             */
/*   Updated: 2022/08/26 19:32:14 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_print_string(char *str)//문자열을 출력해주고, 문자열의 길이를 반환해준다.
{
	int	i;

	i = 0;
	if (str == NULL)//문자열이 없다면
	{
		ft_put_str("(null)");//없다고 출력
		return (6);//(Null)의 길이 6을 반환
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)//% 뒤에 i, d가 오는 경우
{
	int		length;
	char	*num;

	length = 0;
	num = ft_itoa(n);//정수를 문자열로 변환
	length = ft_print_string(num);//문자열의 길이를 재준다.
	free(num);//ft_itoa에 malloc을 사용했으므로 메모리 반환을 해줘야 한다.
	return (length);//길이를 반환
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
