/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:22:51 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*loop_read(char *buffer, int fd, char *str)
{	
	int				bytes;
	int				i;

	i = 0;
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == 0)
		return (str);
	while (buffer[i] && bytes > 0)
	{	
		if (buffer[i] && buffer[i] == '\n')
			return (save(str, buffer, i));
		i++;
		if (i == bytes)
		{
			str = save(str, buffer, i - 1);
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes < 0)
				ft_memset(buffer, '\0', BUFFER_SIZE + 1);
			i = 0;
		}
		if (!buffer[i])
			break ;
	}
	str = save(str, buffer, i);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		buffer[4096][BUFFER_SIZE + 1];
	char			*str;
	int				i;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, buffer[fd], 0) == -1)
	{
		ft_memset(buffer[fd], '\0', BUFFER_SIZE);
		return (NULL);
	}
	str = NULL;
	buffer[fd][BUFFER_SIZE] = '\0';
	i = 0;
	if (buffer[fd][i])
	{	
		while (buffer[fd][i] && buffer[fd][i] != '\n')
			i++;
		if (buffer[fd][i] == '\n' || (!buffer[i] && i < BUFFER_SIZE))
			return (save(str, buffer[fd], i));
		else
			str = save(str, buffer[fd], i);
	}
	str = loop_read(buffer[fd], fd, str);
	return (str);
}
