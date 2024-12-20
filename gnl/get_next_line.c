/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:00:45 by yojin             #+#    #+#             */
/*   Updated: 2024/12/20 14:31:30 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line_end(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	read_file(int fd, char *buffer)
{
	int	count;
	int	i;

	count = read(fd, buffer, BUFFER_SIZE);
	i = count;
	if (count != BUFFER_SIZE)
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
	return (count);
}

int	resize_line(char **line, size_t *max_len)
{
	char	*new;

	*max_len *= 2;
	new = (char *)malloc(sizeof(char) * ((*max_len) + 1));
	if (!new)
	{
		free(*line);
		return (0);
	}
	*new = '\0';
	ft_strcat(new, *line);
	free(*line);
	*line = new;
	return (1);
}

char	*ft_get_line(char *buffer, int fd)
{
	char	*line;
	size_t	max_len;
	size_t	current_len;

	max_len = BUFFER_SIZE;
	line = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!line)
		return (0);
	line[0] = '\0';
	ft_strcat(line, buffer);
	current_len = ft_strlen(buffer);
	while (is_line_end(buffer) == -1)
	{
		if (read_file(fd, buffer) <= 0)
			return (line);
		current_len += ft_strlen(buffer);
		if (max_len < current_len)
			if (!resize_line(&line, &max_len))
				return (0);
		ft_strcat(line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			new_line_pos;
	int			i;

	if (!check_fd(fd, buffer))
		return (0);
	line = ft_get_line(buffer, fd);
	if (!line || ft_strlen(line) == 0)
	{
		free(line);
		return (0);
	}
	i = -1;
	new_line_pos = is_line_end(buffer);
	if (new_line_pos != -1)
		while (++i + new_line_pos + 1 <= BUFFER_SIZE)
			buffer[i] = buffer[i + new_line_pos + 1];
	while (++i < BUFFER_SIZE)
		buffer[i] = '\0';
	return (resize_result(line));
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);

// 	printf("[1] %s", get_next_line(5));
// 	printf("[2] %s", get_next_line(6));
// 	printf("[3] %s", get_next_line(7));
// 	printf("[4] %s", get_next_line(fd));
// 	printf("[5] %s", get_next_line(fd));
// 	printf("[6] %s", get_next_line(fd));

// 	close(fd);
// }
