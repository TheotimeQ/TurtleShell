/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:23:00 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:30 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*gnl_strncat(char *dest, char *src, size_t n)
{
	size_t	index_dest;
	size_t	index_src;
	char	*new_str;

	if (!dest && !src)
		return (NULL);
	if (dest && !src)
		return (dest);
	if (!dest && src)
		return (src);
	new_str = malloc((ft_strlen(dest) + n + 1) * sizeof(char));
	if (new_str == NULL)
	{
		free(dest);
		return (NULL);
	}
	index_src = -1;
	index_dest = -1;
	while (dest[++index_dest])
		new_str[index_dest] = dest[index_dest];
	while (src[++index_src] && index_src < n)
		new_str[index_dest + index_src] = src[index_src];
	new_str[index_dest + index_src] = '\0';
	free(dest);
	return (new_str);
}

char	*save(char *str, char *buffer, int i)
{	
	if (str == NULL)
	{
		str = malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
	}
	str = gnl_strncat(str, buffer, i + 1);
	if (str == NULL)
		return (NULL);
	ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i - 1);
	ft_memset(buffer + BUFFER_SIZE - i - 1, '\0', i + 1);
	return (str);
}
