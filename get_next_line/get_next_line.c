/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:52:37 by jchin             #+#    #+#             */
/*   Updated: 2022/07/04 00:58:32 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<unistd.h>

char	*ft_get_current_total_str(int fd, char *current_str)
{
	char	*buff;
	int		count;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	count = 1;
	while (!ft_strchr(current_str, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[count] = '\0';
		current_str = ft_strjoin(current_str, buff);
	}
	free(buff);
	return (current_str);
}

char	*ft_get_front_line(char *current_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!current_str[i])
		return (NULL);
	while (current_str[i] && current_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (current_str[i] && current_str[i] != '\n')
	{
		str[i] = current_str[i];
		i++;
	}
	if (current_str[i] == '\n')
	{
		str[i] = current_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_current_str(char *current_str)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	while (current_str[i] && current_str[i] != '\n')
		i++;
	if (!current_str[i])
	{
		free(current_str);
		return (NULL);
	}
	string = (char *)malloc(sizeof(char) * (ft_strlen(current_str) - i + 1));
	if (!string)
		return (NULL);
	i++;
	j = 0;
	while (current_str[i])
		string[j++] = current_str[i++];
	string[j] = '\0';
	free(current_str);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*string;
	static char	*current_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	current_str = ft_get_current_total_str(fd, current_str);
	if (!current_str)
		return (NULL);
	string = ft_get_front_line(current_str);
	current_str = ft_new_current_str(current_str);
	return (string);
}
