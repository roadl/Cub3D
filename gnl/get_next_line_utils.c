/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:00:43 by yojin             #+#    #+#             */
/*   Updated: 2024/12/20 14:31:36 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len) != '\0')
		len++;
	return (len);
}

void	ft_strcat(char *dst, char *src)
{
	dst += ft_strlen(dst);
	while (*src && *src != '\n')
	{
		*dst = *src;
		src++;
		dst++;
	}
	if (*src == '\n')
		*dst++ = '\n';
	*dst = '\0';
}

int	check_fd(int fd, char *buffer)
{
	int	i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, NULL, 0) == -1)
	{
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
		return (0);
	}
	return (1);
}

char	*resize_result(char *line)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!result)
	{
		free(line);
		return (0);
	}
	result[0] = '\0';
	ft_strcat(result, line);
	free(line);
	return (result);
}
